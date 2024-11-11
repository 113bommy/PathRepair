#include <bits/stdc++.h>
using namespace std;
const int mx = 100 + 10;
int m;
long long num[mx];
vector<int> g[mx], r[1 << 18];
map<int, int> mp;
map<int, int> mvis;
stack<int> sta;
pair<int, int> s[mx * mx];
int vis[1 << 18], siz;
bool vis2[1 << 18];
pair<int, int> ans[mx];
long long reg;
int get_ed(int x) {
  long long y = reg - num[mp[x]] + x;
  return mp.count(y) ? y : -1;
}
void full(int u) {
  int y = 0;
  bool mark[20];
  memset(mark, 0, sizeof(mark));
  while (sta.top() != u) {
    int v = sta.top();
    sta.pop();
    if (mark[mp[v]]) return;
    mark[mp[v]] = 1;
    y |= 1 << (mp[v] - 1);
  }
  if (mark[mp[u]]) return;
  y |= 1 << (mp[u] - 1);
  if (vis2[y]) return;
  vis2[y] = 1;
  s[siz++] = pair<int, int>(y, u);
}
void dfs(int u) {
  if (mvis[u] == 2) return;
  if (mvis[u] == 1) {
    full(u);
    return;
  }
  mvis[u] = 1;
  sta.push(u);
  int v = get_ed(u);
  if (v != -1) dfs(v);
  mvis[u] = 2;
}
int main() {
  long long sum = 0;
  int cnt = 0;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int c, u;
    scanf("%d", &c);
    for (int j = 0; j < c; j++) {
      scanf("%d", &u);
      g[i].push_back(u);
      mp[u] = i;
      num[i] += u, sum += u;
    }
  }
  if (sum % m) return 0 * puts("No");
  reg = sum / m;
  for (int i = 1; i <= m; i++) {
    for (int j : g[i])
      if (!mvis[j]) dfs(j);
  }
  vis[0] = 1;
  for (int i = 1; i < (1 << m); i++) {
    for (int j = 0; j < siz; j++)
      if ((i & s[j].first) == s[j].first) {
        vis[i] = vis[i ^ s[j].first];
        if (vis[i]) {
          r[i].push_back(s[j].second);
          r[i].insert(r[i].end(), r[i ^ s[j].first].begin(),
                      r[i ^ s[j].first].end());
          break;
        }
      }
  }
  int bv = (1 << m) - 1;
  if (r[bv].size()) {
    puts("Yes");
    for (int i : r[bv]) {
      int j = i;
      do {
        int nj = get_ed(j);
        int np = mp[j];
        ans[mp[nj]] = pair<int, int>(nj, np);
        swap(j, nj);
      } while (j != i);
    }
    for (int i = 1; i <= m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  } else
    puts("No");
  return 0;
}
