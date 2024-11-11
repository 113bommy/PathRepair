#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
long long n, m, k, a[N], c;
long long res;
pair<long long, long long> q[N], st[N], ed[N];
int main() {
  scanf("%I64d%I64d%I64d", &n, &k, &m);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  for (int i = 1, t = 1; i <= n; i = t + 1) {
    t = i;
    while (a[t + 1] == a[t]) t++;
    if ((t - i + 1) % k) q[++c] = make_pair(a[i], (t - i + 1) % k);
    while (q[c].first == q[c - 1].first && c > 1) {
      c--;
      q[c].second += q[c + 1].second;
      q[c].second %= k;
      if (!q[c].second) c--;
    }
  }
  for (int i = 1; i <= c; ++i) st[i] = ed[i] = q[i], res += q[i].second;
  res *= m;
  int l = 1, r = c;
  int stl = 1, edl = 1, str = c, edr = c;
  while (l <= r) {
    if (l == r) {
      if (q[l].second * m >= k) {
        long long t = q[l].second * m % k;
        res -= (q[l].second * m - t);
        if (t) return 0 * printf("%I64d", res);
        int c1 = c;
        c = 0;
        str--;
        edl++;
        for (int i = 1; i <= str; ++i) {
          q[++c] = st[i];
          while (q[c].first == q[c - 1].first) {
            c--;
            q[c].second += q[c + 1].second;
            res -= (q[c].second / k) * k;
            q[c].second %= k;
            if (!q[c].second) c--;
          }
        }
        for (int i = edl; i <= c1; ++i) {
          q[++c] = ed[i];
          while (q[c].first == q[c - 1].first && c > 1) {
            c--;
            q[c].second += q[c + 1].second;
            res -= (q[c].second / k) * k;
            q[c].second %= k;
            if (!q[c].second) c--;
          }
        }
        break;
      } else
        break;
    } else if (q[r].first == q[l].first && q[r].second + q[l].second >= k) {
      long long t = (q[r].second + q[l].second) % k;
      res -= (q[r].second + q[l].second - t) * (m - 1);
      q[r].second = t;
      q[str].second = t;
      if (!q[r].second) r--, str--;
      l++;
      edl++;
    } else
      break;
  }
  return 0 * printf("%I64d", res);
}
