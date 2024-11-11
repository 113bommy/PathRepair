#include <bits/stdc++.h>
using namespace std;
int n, m, first[200005], second[200005];
int dep[200005], fa[200005];
vector<int> edge[200005], ans;
pair<int, int> tag[200005];
void dfs(int first) {
  for (int i = 0; i < edge[first].size(); ++i) {
    int v = edge[first][i];
    if (dep[v]) continue;
    fa[v] = first;
    dep[v] = dep[first] + 1;
    dfs(v);
  }
}
void out() {
  printf("%d ", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
  puts("");
  ans.clear();
}
void get(int first, int second) {
  vector<int> a;
  a.clear();
  int op = 0;
  if (dep[first] < dep[second]) swap(first, second), op = 1;
  while (first != second) {
    a.push_back(first);
    first = fa[first];
  }
  a.push_back(first);
  if (op) reverse(a.begin(), a.end());
  for (int i = 0; i < a.size(); ++i) ans.push_back(a[i]);
}
void solve(int first, int a, int b) {
  puts("YES");
  int c = tag[first].first, d = tag[first].second;
  if (dep[b] < dep[d]) swap(b, d), swap(a, c);
  get(first, b);
  out();
  get(first, a);
  ans.push_back(b);
  out();
  get(first, c);
  get(b, d);
  out();
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &first[i], &second[i]);
    edge[first[i]].push_back(second[i]);
    edge[second[i]].push_back(first[i]);
  }
  for (int i = 1; i <= n; ++i)
    if (!dep[i]) {
      dep[i] = 1;
      dfs(i);
    }
  for (int i = 1; i <= m; ++i) {
    if (dep[first[i]] < dep[second[i]]) swap(first[i], second[i]);
    int u = first[i], v = second[i];
    if (fa[u] != v) {
      while (u != v) {
        if (tag[u].first) {
          solve(u, first[i], second[i]);
          return 0;
        }
        tag[u] = make_pair(first[i], second[i]);
        u = fa[u];
      }
    }
  }
  puts("NO");
  return 0;
}
