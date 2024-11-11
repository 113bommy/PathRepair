#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, m;
vector<pair<int, char> > edges[MAXN];
int val[MAXN];
int vis[MAXN];
char letter;
vector<int> comp;
int mini = 1e9, oa, answer = 0, answer2 = 0;
char lea;
void solve(int node, int on) {
  val[node] = on;
  vis[node] = 1;
  for (pair<int, char>& t : edges[node]) {
    if (vis[t.first]) continue;
    if (on == (t.second != letter))
      solve(t.first, 0);
    else
      solve(t.first, 1);
  }
}
void get(int on, char let) {
  letter = let;
  for (int y : comp) val[y] = vis[y] = 0;
  solve(comp[0], on);
  int ans = 0;
  for (int g : comp) ans += val[g];
  bool flag = 1;
  for (int g : comp) {
    for (pair<int, char>& y : edges[g]) {
      if ((val[g] ^ val[y.first]) != (y.second != let)) flag = 0;
    }
  }
  if (!flag) return;
  if (ans < mini) mini = ans, oa = on, lea = let;
}
void dfs(int node) {
  comp.push_back(node);
  vis[node] = 1;
  for (pair<int, char>& g : edges[node]) {
    if (vis[g.first]) continue;
    dfs(g.first);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int g = 0; g < m; g++) {
    int a, b;
    cin >> a >> b;
    char c;
    cin >> c;
    edges[a].push_back(pair<int, char>(b, c));
    edges[b].push_back(pair<int, char>(a, c));
  }
  vector<int> vo, vo2;
  for (int g = 1; g <= n; g++) {
    if (vis[g]) continue;
    mini = 1e9;
    comp.clear();
    dfs(g);
    get(0, 'B');
    get(1, 'B');
    if (mini == 1e9) {
      answer = 1e9;
    }
    answer += mini;
    letter = lea;
    for (int y : comp) val[y] = vis[y] = 0;
    solve(comp[0], oa);
    for (int y : comp) {
      if (val[y]) vo.push_back(y);
    }
  }
  memset(vis, 0, sizeof(vis));
  memset(val, 0, sizeof(val));
  mini = 1e9, oa = 0;
  for (int g = 1; g <= n; g++) {
    if (vis[g]) continue;
    mini = 1e9;
    comp.clear();
    dfs(g);
    get(0, 'R');
    get(1, 'R');
    if (mini == 1e9) {
      answer = 1e9;
    }
    answer2 += mini;
    letter = lea;
    for (int y : comp) val[y] = vis[y] = 0;
    solve(comp[0], oa);
    for (int y : comp) {
      if (val[y]) vo2.push_back(y);
    }
  }
  if (min(answer, answer2) >= 1e9) {
    cout << -1;
    return 0;
  }
  if (answer < answer2) {
    cout << answer << '\n';
    for (int t : vo) cout << t << ' ';
  } else {
    cout << answer2 << '\n';
    for (int t : vo2) cout << t << ' ';
  }
  return 0;
}
