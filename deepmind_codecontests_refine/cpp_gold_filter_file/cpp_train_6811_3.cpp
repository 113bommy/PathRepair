#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 123;
const int mod = 1e9 + 7;
const int INF = 1e9 + 1;
const double eps = 1e-9;
const double pi = acos(-1.0);
int n, f[MAXN], inv[MAXN], a[5001];
map<int, int> m;
int mult(int a, int b) { return (1ll * a * b) % mod; }
int binp(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = mult(ans, a);
    a = mult(a, a);
    n >>= 1;
  }
  return ans;
}
int cnk(int n, int k) {
  int ans = f[n];
  ans = mult(ans, inv[k]);
  ans = mult(ans, inv[n - k]);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  f[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    f[i] = mult(f[i - 1], i);
    inv[i] = binp(f[i], mod - 2);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 2; j <= sqrt(a[i]); j++) {
      while (a[i] % j == 0) {
        m[j]++;
        a[i] /= j;
      }
    }
    if (a[i] - 1) m[a[i]]++;
  }
  int sum = 1;
  for (auto i : m) {
    sum = mult(sum, cnk(i.second + n - 1, n - 1));
  }
  cout << sum;
  return 0;
}
