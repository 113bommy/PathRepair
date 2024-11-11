#include <bits/stdc++.h>
using namespace std;
const long long MAX = 200010;
const long long MOD = (long long)1e9 + 7;
const long long INF = 1e9;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
long long m;
pair<long long, long long> cicle(long long h1, long long a1, long long x1,
                                 long long y1) {
  long long val = h1, t = -1, p = -1;
  for (long long i = 0; i <= 2 * m; i++) {
    if (val == a1 and t != -1 and p == -1) p = i - t;
    if (val == a1 and t == -1) t = i;
    val = (x1 * val + y1) % m;
  }
  return make_pair(t, p);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long h1, a1, x1, y1, h2, a2, x2, y2;
  cin >> m;
  cin >> h1 >> a1 >> x1 >> y1;
  cin >> h2 >> a2 >> x2 >> y2;
  long long t1, p1, t2, p2;
  tie(t1, p1) = cicle(h1, a1, x1, y1);
  tie(t2, p2) = cicle(h2, a2, x2, y2);
  if (t1 == -1 or t2 == -1) {
    cout << -1 << '\n';
  } else if (p1 == -1 and p2 == -1) {
    cout << (t1 == t2 ? t1 : -1) << '\n';
  } else if (p1 == -1) {
    if ((t1 - t2) >= 0 and (t1 - t2) % p2 == 0)
      cout << t1 << '\n';
    else
      cout << -1 << '\n';
  } else if (p2 == -1) {
    if ((t2 - t1) >= 0 and (t2 - t1) % p1 == 0)
      cout << t2 << '\n';
    else
      cout << -1 << '\n';
  } else if (p1 == 0 or p2 == 0) {
    cout << max(t1, t2) << '\n';
  } else if (t1 == t2) {
    cout << t1 << '\n';
  } else {
    long long res = INF;
    long long eita = abs(t2 - t1);
    for (long long k1 = 0; k1 < 40000000; k1++) {
      long long val = t1 + k1 * p1 - t2;
      if (val > 0 and val % (1ll * p2) == 0) res = min(res, t1 + k1 * p1);
    }
    for (long long k2 = 0; k2 < 40000000; k2++) {
      long long val = t2 + k2 * p2 - t1;
      if (val > 0 and val % (1ll * p1) == 0) res = min(res, t2 + k2 * p2);
    }
    cout << (res >= INF ? -1 : res) << '\n';
  }
  return 0;
}
