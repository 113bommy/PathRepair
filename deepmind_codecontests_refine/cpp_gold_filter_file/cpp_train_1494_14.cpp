#include <bits/stdc++.h>
using namespace std;
int n, m, k, t[200005];
vector<pair<int, int> > cnt[200005];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
  }
  int now = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (t[i] != t[i + 1]) {
      cnt[t[i]].push_back(make_pair(now, i));
      now = i + 1;
    }
  }
  cnt[t[n - 1]].push_back(make_pair(now, n - 1));
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int l = 0, r = 0, tot = 0, pp = 0;
    while (l < cnt[i].size()) {
      while (r < cnt[i].size()) {
        if (l != r) {
          int gg = pp + (cnt[i][r].first - cnt[i][r - 1].second - 1);
          if (gg > k) break;
          pp = gg;
        }
        tot += (cnt[i][r].second - cnt[i][r].first + 1);
        ++r;
      }
      if (tot > ans) ans = tot;
      if (r >= cnt[i].size()) break;
      ++l;
      if (l != cnt[i].size()) {
        if (l != r) pp -= (cnt[i][l].first - cnt[i][l - 1].second - 1);
        tot -= (cnt[i][l - 1].second - cnt[i][l - 1].first + 1);
      }
    }
  }
  printf("%d\n", ans);
}
