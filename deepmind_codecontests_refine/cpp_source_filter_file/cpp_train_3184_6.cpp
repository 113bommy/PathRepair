#include <bits/stdc++.h>
using namespace std;
const int MAXN = int(2e5);
const int MOD = int(360);
const long long oo = LLONG_MAX;
long long ts, tf, t;
int n;
vector<pair<long long, long long> > a;
long long ans, best;
void update(long long w, long long x) {
  if (x < tf && best > w) {
    best = w;
    ans = x;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> ts >> tf >> t >> n) {
    a.clear();
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (a.empty() || a.back().first != x) a.push_back({x, 0});
      a.back().second++;
    }
    long long curt = ts;
    ans = -1;
    best = oo;
    update(ts, 0);
    if (n) {
      if (ts < a[0].first)
        update(0, ts);
      else
        update(ts - a[0].first + 1, a[0].first - 1);
    } else
      update(0, ts);
    for (int i = 0; i < int((a).size()); i++) {
      long long t1 = a[i].first - 1;
      if (curt <= t1)
        update(0, curt);
      else
        update(curt - t1, t1);
      curt = max(curt, a[i].first);
      curt += a[i].second * t;
      update(curt - a[i].first, a[i].first);
    }
    update(0, curt);
    cout << ans << "\n";
  }
  return 0;
}
