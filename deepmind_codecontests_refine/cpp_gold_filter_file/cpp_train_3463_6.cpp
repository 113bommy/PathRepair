#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > mush;
vector<pair<pair<long long, long long>, long long> > t;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    q;
int main() {
  int n, m;
  long long x, h, l, r, v;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    cin >> x >> h >> l >> r;
    t.push_back(make_pair(make_pair(x - h, x - 1ll), 100ll - l));
    t.push_back(make_pair(make_pair(x + 1ll, x + h), 100ll - r));
  }
  for (int i = 0; i < m; ++i) {
    cin >> x >> v;
    mush.push_back(make_pair(x, v));
  }
  sort(t.begin(), t.end());
  sort(mush.begin(), mush.end());
  double p = 0, ans = 0;
  int pos = 0, cnt = 0;
  for (int i = 0; i < m; ++i) {
    long long x = mush[i].first;
    while (q.size() && q.top().first < x) {
      pair<long long, long long> tt = q.top();
      q.pop();
      if (tt.second)
        p -= log(tt.second) - log(100);
      else
        --cnt;
    }
    while (pos < n * 2 && t[pos].first.first <= x) {
      if (t[pos].first.second >= x) {
        if (t[pos].second) {
          p += log(t[pos].second) - log(100);
        } else
          ++cnt;
        q.push(make_pair(t[pos].first.second, t[pos].second));
      }
      ++pos;
    }
    if (!cnt) ans += mush[i].second * exp(p);
  }
  printf("%.10f\n", ans);
  return 0;
}
