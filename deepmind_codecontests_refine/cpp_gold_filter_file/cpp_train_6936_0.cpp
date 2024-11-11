#include <bits/stdc++.h>
using namespace std;
const int Max = 2000007;
long long f[Max], ff[Max];
const int mod = 1e9 + 7;
int prime[1010], cnt;
bool st[2020];
int m(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    b >>= 1;
    a = 1ll * a * a % mod;
  }
  return res;
}
int C(int a, int b) { return f[a] * ff[a - b] % mod * ff[b] % mod; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  f[0] = ff[0] = 1;
  for (int i = 1; i < Max; i++) {
    f[i] = 1ll * f[i - 1] * i % mod;
  }
  for (int i = 1; i < Max; i++) {
    ff[i] = m(f[i], mod - 2);
  }
  for (int i = 2; i <= 1010; i++) {
    if (!st[i]) {
      prime[cnt++] = i;
    }
    for (int j = 0; i * prime[j] <= 1010; j++) {
      st[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    long long res = 1;
    for (int i = 0; i < cnt; i++) {
      if (prime[i] * prime[i] > x) {
        break;
      }
      if (x % prime[i] == 0) {
        int ct = 0;
        while (x % prime[i] == 0) {
          x /= prime[i];
          ct++;
        }
        res = res * C(ct + y - 1, y - 1) % mod;
      }
    }
    if (x != 1) {
      res = res * y % mod;
    }
    cout << res * m(2, y - 1) % mod << endl;
  }
  return 0;
}
