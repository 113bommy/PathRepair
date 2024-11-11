#include <bits/stdc++.h>
using namespace std;
int a[1 << 22], b[1 << 22];
const int mod = 998244353;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
struct FWT {
  int mod = 998244353;
  int rev = qpow(2, mod - 2);
  int add(int a, int b) {
    if (a + b >= mod) return a + b - mod;
    if (a + b < 0) return a + b + mod;
    return a + b;
  }
  int mul(int a, int b) { return (long long)a * b % mod; }
  void fwt(int a[], int n, int op) {
    for (int d = 1; d < n; d <<= 1) {
      for (int m = d << 1, i = 0; i < n; i += m) {
        for (int j = 0; j < d; j++) {
          int x = a[i + j], y = a[i + j + d];
          if (op == 0)
            a[i + j] = add(x, y), a[i + j + d] = add(x, -y);
          else
            a[i + j] = mul(add(x, y), rev), a[i + j + d] = mul(add(x, -y), rev);
        }
      }
    }
  }
  void solve(int a[], int b[], int n) {
    fwt(a, n, 0);
    fwt(b, n, 0);
    for (int i = (0); i < (n); i++) a[i] = mul(a[i], b[i]);
    fwt(a, n, 1);
  }
} Fwt;
char maze[25][100000 + 10];
int get(int x, int n) {
  int cnt = 0;
  while (x) {
    if (x % 2 == 1) cnt++;
    x /= 2;
  }
  return min(cnt, n - cnt);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++) cin >> maze[i][j];
  }
  for (int i = (0); i < (m); i++) {
    int sta = 0;
    for (int j = (0); j < (n); j++)
      if (maze[j][i] == '1') sta |= (1 << j);
    a[sta]++;
  }
  for (int i = (0); i < (1 << n); i++) {
    b[i] = get(i, n);
  }
  Fwt.solve(a, b, 1 << n);
  int ans = 1e9;
  for (int i = (0); i < (1 << n); i++) {
    ans = min(ans, a[i]);
  }
  cout << ans << "\n";
  return 0;
}
