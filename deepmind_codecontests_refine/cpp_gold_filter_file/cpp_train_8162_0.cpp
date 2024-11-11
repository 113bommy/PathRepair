#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[100010];
vector<pair<int, int> > V, nV;
int main() {
  scanf("%d %d", &n, &m);
  int x, y;
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &x, &y);
    a[i] = make_pair(x, y);
  }
  sort(a + 1, a + m + 1);
  int px = 0, cur = 1;
  V.push_back(make_pair(1, 1));
  while (cur <= m) {
    if (V.size() > 0 && a[cur].first != px + 1) {
      int st = V[0].first;
      V.clear();
      V.push_back(make_pair(st, n));
    }
    int ncur = cur;
    while (a[ncur].first == a[cur].first) ++ncur;
    int st = 1, idx = 0;
    nV.clear();
    for (int i = cur; i <= ncur; ++i) {
      int ed = (i < ncur) ? (a[i].second - 1) : n;
      while (idx < V.size() && V[idx].second < st) ++idx;
      if (idx < V.size() && max(V[idx].first, st) <= ed)
        nV.push_back(make_pair(max(V[idx].first, st), ed));
      st = ed + 2;
    }
    V = nV;
    px = a[cur].first;
    cur = ncur;
  }
  if (V.size() > 0 && (px < n || V[V.size() - 1].second == n))
    printf("%d\n", n * 2 - 2);
  else
    printf("-1\n");
  return 0;
}
