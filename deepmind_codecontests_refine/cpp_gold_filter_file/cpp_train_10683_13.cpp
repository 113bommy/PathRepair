#include <bits/stdc++.h>
using namespace std;
int ok[100005], mk[100005];
vector<int> g[100005];
bool cmp(int u, int v) {
  if (u == v) return 0;
  if (mk[v] && !mk[u]) return 1;
  if (mk[v] && u > v) return 1;
  if (!mk[u] && u > v) return 1;
  return 0;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int> > s(n, vector<int>());
  int len = 0;
  for (int i = 0; i < n; i++) {
    int l;
    scanf("%d", &l);
    len = max(len, l);
    while (l--) {
      int x;
      scanf("%d", &x);
      s[i].push_back(x);
    }
  }
  vector<vector<int> > q(len);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i].size(); j++) q[j].push_back(i);
  }
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < q[i].size(); j++) {
      auto& u = q[i][j];
      if (j == 0 || q[i][j - 1] != u - 1) ok[u] = 1;
      if (ok[u]) continue;
      auto& v = q[i][j - 1];
      if (s[v][i] != s[u][i]) g[s[v][i]].push_back(s[u][i]), ok[u] = 1;
      if (s[v].size() == s[u].size() && s[u].size() == i + 1) ok[u] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    if (!ok[i]) return puts("No"), 0;
  vector<int> res;
  for (int i = m; i >= 1; i--) {
    for (auto& j : g[i])
      if (cmp(i, j)) mk[i] = 1, res.push_back(i);
  }
  for (int i = m; i >= 1; i--) {
    for (auto& j : g[i])
      if (cmp(i, j)) return puts("No"), 0;
  }
  puts("Yes");
  printf("%d\n", res.size());
  sort(res.begin(), res.end());
  for (auto& u : res) printf("%d ", u);
  puts("");
  return 0;
}
