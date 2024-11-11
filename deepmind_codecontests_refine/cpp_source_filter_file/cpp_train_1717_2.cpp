#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const long long int mod = 1e9 + 7;
const long long int inf = 2e9 + 100;
long long int n, k, l, m;
long long int tmp[2][2];
long long int Pw(long long int x, long long int n) {
  if (n == 0) return 1;
  long long int y = (x * x) % m;
  if (n % 2 == 0) return Pw(y, n / 2);
  return (Pw(y, n / 2) * x) % m;
}
inline void mul(long long int a[2][2], long long int b[2][2],
                long long int res[2][2]) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) res[i][j] = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        res[i][j] += (a[i][k] * b[k][j]) % m;
        res[i][j] %= m;
      }
    }
  }
}
inline void pw(long long int a[2][2], long long int p) {
  long long int res[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) res[i][j] = 0;
    res[i][i] = 1;
  }
  while (p) {
    if (p & 1ll) {
      mul(res, a, tmp);
      memcpy(res, tmp, sizeof tmp);
    }
    mul(a, a, tmp);
    memcpy(a, tmp, sizeof tmp);
    p /= 2ll;
  }
  memcpy(a, res, sizeof res);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k >> l >> m;
  for (int i = l; i < 64; i++) {
    if ((k >> i) & 1) {
      cout << 0 << endl;
      return 0;
    }
  }
  long long int mt[2][2] = {{1, 1}, {1, 0}};
  pw(mt, n + 1);
  long long int a = (Pw(2, n) - mt[0][0] + m) % m, ans = 1;
  for (int i = 0; i < l; i++) {
    if ((k >> i) & 1)
      ans *= a;
    else
      ans *= mt[0][0];
    ans %= m;
  }
  cout << ans << endl;
  return 0;
}
