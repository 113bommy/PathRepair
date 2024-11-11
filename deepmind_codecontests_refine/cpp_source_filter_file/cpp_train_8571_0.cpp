#include <bits/stdc++.h>
using namespace std;
int n, k;
const int C = 200005;
vector<int> tab[C];
vector<pair<int, int>> fools;
int jump[C][20];
bool visited[C];
int pre[C];
int post[C];
int cnt = 0;
unordered_map<long long, int> m;
int res[C];
int l[C];
int travelers[C];
bool visted[C];
void dfs(int x) {
  visited[x] = 1;
  pre[x] = cnt;
  cnt++;
  for (int i = 0; i < tab[x].size(); i++) {
    if (!visited[tab[x][i]]) {
      jump[tab[x][i]][0] = x;
      dfs(tab[x][i]);
    }
  }
  post[x] = cnt;
  cnt++;
}
bool ancestor(int x, int y) { return pre[x] < pre[y] && post[x] > post[y]; }
int lca(int x, int y) {
  if (x == y) return x;
  if (ancestor(x, y)) return x;
  if (ancestor(y, x)) return y;
  if (ancestor(jump[y][0], x)) return jump[y][0];
  int l = 0, r = 19;
  while (l + 1 < r) {
    int s = (l + r) / 2;
    if (ancestor(jump[y][s], x))
      r = s;
    else
      l = s;
  }
  if (y == jump[y][l]) return -1;
  return lca(x, jump[y][l]);
}
int dfs1(int x) {
  visted[x] = 1;
  int sum = 0;
  for (int i = 0; i < tab[x].size(); i++) {
    if (!visted[tab[x][i]]) {
      int s = dfs1(tab[x][i]);
      sum += s;
      long long p = (long long)x * 1000000 + tab[x][i];
      res[m[p]] += s;
    }
  }
  return sum + travelers[x] - (2 * l[x]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    m[a * 1000000 + b] = i;
    m[b * 1000000 + a] = i;
    tab[a].push_back(b);
    tab[b].push_back(a);
  }
  dfs(1);
  pre[0] = -1;
  post[0] = 1000000001;
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      jump[j][i] = jump[jump[j][i - 1]][i - 1];
    }
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    fools.push_back(make_pair(a, b));
    travelers[a]++;
    travelers[b]++;
    int c = lca(a, b);
    l[c]++;
  }
  dfs1(1);
  for (int i = 0; i < n - 1; i++) {
    cout << res[i] << " ";
  }
  return 0;
}
