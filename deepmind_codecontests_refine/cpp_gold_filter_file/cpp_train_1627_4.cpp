#include <bits/stdc++.h>
using namespace std;
long long G(long long a, long long b) {
  if (b == 0) return a;
  return G(b, a % b);
}
const long long mod = 1000000007ll;
long long a[111111], b[111111], s[111111];
pair<long long, long long> p[111111], p1[111111], p2[111111];
int main() {
  ios_base::sync_with_stdio(false);
  long long n, m, k = 0, ka = 0, kb = 0, kc = 0, q = 0, w = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> a[i] >> b[i];
    k += s[i];
    if (a[i] > b[i]) ka += s[i];
    if (a[i] < b[i]) kb += s[i];
    if (a[i] == b[i]) kc += s[i];
    q += s[i] * (max(a[i], b[i]));
    p[i].first = a[i] - b[i];
    p[i].second = i;
  }
  k = (k + m - 1) / m;
  if ((ka + m - 1) / m + (kb + m - 1) / m <= k) {
    cout << q;
    return 0;
  }
  sort(p, p + n);
  long long qq = ka % m, ww = kb % m, e = 0, ee = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].first <= 0) continue;
    if (qq == 0) break;
    e += min(qq, s[p[i].second]) * p[i].first;
    qq -= min(qq, s[p[i].second]);
  }
  reverse(p, p + n);
  for (int i = 0; i < n; i++) {
    if (p[i].first >= 0) continue;
    if (ww == 0) break;
    ee -= min(ww, s[p[i].second]) * p[i].first;
    ww -= min(ww, s[p[i].second]);
  }
  cout << q - min(e, ee);
}
