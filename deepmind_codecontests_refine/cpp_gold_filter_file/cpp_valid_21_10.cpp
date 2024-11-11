#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const long long mod = 998244353;
int n, s[maxn];
long long x[maxn], y[maxn], qzh[maxn], f[maxn];
int search(int a) {
  int l = 1, r = n;
  while (l <= r) {
    if (r - l <= 10) {
      for (int i = l; i <= r; i++)
        if (a < x[i]) return i;
    }
    int mid = (l + r) / 2;
    if (a <= x[mid])
      r = mid;
    else
      l = mid;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld%d", &x[i], &y[i], &s[i]);
  }
  long long ans = 0;
  x[0] = 0;
  f[0] = 0;
  ans = x[n] + 1;
  for (int i = 1; i <= n; i++) {
    int p = search(y[i]);
    long long q = 0;
    q += qzh[i - 1] - qzh[p - 1] + x[i] - y[i];
    f[i] = q % mod;
    qzh[i] = (qzh[i - 1] + f[i]) % mod;
    if (s[i]) ans = (ans + f[i]);
  }
  cout << (ans % mod + mod) % mod << endl;
  return 0;
}
