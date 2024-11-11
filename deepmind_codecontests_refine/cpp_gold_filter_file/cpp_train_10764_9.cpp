#include <bits/stdc++.h>
using namespace std;
struct okr {
  pair<int, int> p;
  int r;
};
okr a[1010];
pair<int, int> p[1010];
int num[1010];
int h[1010];
bool use[1010];
vector<int> g[1010];
int first[1010];
vector<int> ord;
int t[2000000];
int sz;
void dfs(int v, int h1) {
  use[v] = true;
  first[v] = ord.size();
  ord.push_back(h1);
  h[v] = h1;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (!use[to]) {
      dfs(to, h1 + 1);
      ord.push_back(h1);
    }
  }
}
inline long long dist(pair<int, int> a, pair<int, int> b) {
  return (1ll * (a.first - b.first) * (a.first - b.first) +
          1ll * (a.second - b.second) * (a.second - b.second));
}
int find(int i, int first, int second, int l, int r) {
  if (i > 2 * sz - 1 || first > r || second < l) return 10000000;
  if (first >= l && second <= r) return t[i];
  return min(find(2 * i, first, (first + second) / 2, l, r),
             find(2 * i + 1, (first + second) / 2 + 1, second, l, r));
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  m++;
  a[0].p = make_pair(0, 0);
  a[0].r = 1000000001;
  for (int i = 0; i < n; i++) scanf("%d %d", &p[i].first, &p[i].second);
  for (int i = 0; i < m - 1; i++)
    scanf("%d %d %d", &a[i + 1].r, &a[i + 1].p.first, &a[i + 1].p.second);
  int minn = 1000000002, mini = 0;
  for (int i = 0; i < n; i++) {
    minn = 1000000002;
    for (int j = 0; j < m; j++)
      if (dist(p[i], a[j].p) < 1ll * a[j].r * a[j].r)
        if (minn > a[j].r) {
          mini = j;
          minn = a[j].r;
        }
    num[i] = mini;
  }
  for (int i = 1; i < m; i++) {
    minn = 1000000002, mini = 0;
    for (int j = 0; j < m; j++)
      if (dist(a[i].p, a[j].p) < 1ll * a[j].r * a[j].r && a[i].r < a[j].r) {
        if (minn > a[j].r) {
          minn = a[j].r;
          mini = j;
        }
      }
    g[mini].push_back(i);
  }
  memset(use, false, sizeof(use));
  for (int i = 0; i < m; i++)
    if (!use[i]) dfs(i, 0);
  for (int i = 0; i < 2000000; i++) t[i] = 100000000;
  sz = 1;
  while (sz < ord.size()) sz *= 2;
  for (int i = sz; i < 2 * sz; i++) {
    if (ord.size() <= i - sz) break;
    t[i] = ord[i - sz];
  }
  for (int i = sz - 1; i >= 0; i--) t[i] = min(t[2 * i], t[2 * i + 1]);
  int t1, t2;
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &t1, &t2);
    printf(
        "%d\n",
        h[num[t1 - 1]] + h[num[t2 - 1]] -
            2 * find(1, 1, sz, min(first[num[t1 - 1]], first[num[t2 - 1]]) + 1,
                     max(first[num[t1 - 1]], first[num[t2 - 1]]) + 1));
  }
  return 0;
}
