#include <bits/stdc++.h>
const int N = 1e5 + 2;
using namespace std;
int n, w, h, g[N], p[N], t[N];
vector<int> grp[N + N];
pair<int, int> ans[N];
int main() {
  scanf(" %d %d %d", &n, &w, &h);
  for (int i = 0; i < n; i++) {
    scanf(" %d %d %d", &g[i], &p[i], &t[i]);
    grp[p[i] - t[i] + N].push_back(i);
  }
  vector<int> xs, ys;
  for (int i = 0; i < N + N; i++) {
    if (grp[i].empty()) continue;
    for (int d : grp[i]) {
      if (g[d] == 1)
        xs.push_back(p[d]);
      else
        ys.push_back(p[d]);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    sort(grp[i].begin(), grp[i].end(), [](int a, int b) {
      if (g[a] != g[b]) return g[a] == 2;
      if (g[a] == 1) return p[a] < p[b];
      return p[a] > p[b];
    });
    int l = 0, r = ys.size();
    for (int d : grp[i]) {
      ans[d].first = (l < xs.size()) ? xs[l] : w;
      ans[d].second = (l < xs.size()) ? h : ys[--r];
      l++;
    }
    xs.clear();
    ys.clear();
  }
  for (int i = 0; i < n; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
