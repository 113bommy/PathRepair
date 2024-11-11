#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 100006;
const int mxm = 5006;
ll n, m, K, P;
ll h[mxn], a[mxn];
ll c[mxm];
bool check(ll x) {
  ll cnt = 0;
  fill(c, c + m + 1, 0);
  for (int i = 0; i < n; ++i) {
    ll hei = x;
    ({
      if (!((hei -= a[i]) >= 0)) return false;
    });
    for (ll j = m - 1;;) {
      ll t = 0;
      ll low = (j ? a[i] : h[i]);
      if (hei < low) t += (low - hei + P - 1) / P;
      c[j] += t;
      hei += t * P;
      ({
        if (!((cnt += t) <= m * K)) return false;
      });
      if (j == 0) break;
      ll d = min(j, hei / a[i]);
      hei -= a[i] * d;
      j -= d;
    }
  }
  for (int i = 0; i < m; ++i)
    if (c[i] > K) c[i + 1] += c[i] - K;
  return !c[m];
}
void EXEC() {
  cin >> n >> m >> K >> P;
  for (int i = 0; i < n; ++i) scanf("%lld%lld", &h[i], &a[i]);
  ll L = 0, R = (m + 1) * 1000000000LL, M;
  while (L < R)
    if (check(M = L + R >> 1))
      R = M;
    else
      L = M + 1;
  cout << L << endl;
}
int main() {
  EXEC();
  return 0;
}
