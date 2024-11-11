#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
vector<pair<int, int>> mp[100005];
vector<pair<int, pair<int, int>>> ans;
bool vis[100005 * 2];
int cnt;
int dfs(int x, int pa) {
  vector<int> v;
  for (auto p : mp[x]) {
    int c = p.first, id = p.second;
    if (vis[id] || c == pa) continue;
    vis[id] = 1;
    vis[id ^ 1] = 1;
    int rm = dfs(c, x);
    if (rm != -1) {
      ans.push_back({c, {x, rm}});
    } else {
      v.push_back(c);
    }
  }
  while (v.size() > 1) {
    int a = v.back();
    v.pop_back();
    int b = v.back();
    v.pop_back();
    ans.push_back({x, {a, b}});
  }
  if (v.empty()) return -1;
  return v[0];
}
int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  if (m & 1) {
    puts("No solution");
    return 0;
  }
  for (int(i) = 0; (i) < (int)(m); (i)++) {
    scanf("%d%d", &u, &v);
    mp[u].push_back({v, cnt++});
    mp[v].push_back({u, cnt++});
  }
  dfs(1, 0);
  for (auto p : ans)
    printf("%d %d %d\n", p.second.first, p.first, p.second.second);
  return 0;
}
