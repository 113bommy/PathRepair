#include <bits/stdc++.h>
using namespace std;
const int MAXN = 201;
int cnt[MAXN];
bool mark[MAXN * MAXN];
int in[MAXN];
vector<int> ans;
set<pair<int, int> > E;
vector<vector<pair<int, int> > > g(MAXN);
bool visit[MAXN];
void reset() {
  ans.resize(0);
  memset(in, 0, sizeof(in));
  memset(mark, false, sizeof(mark));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < MAXN; i++) g[i].resize(0);
  memset(visit, false, sizeof(visit));
  E.clear();
}
void Euler_path(int u) {
  visit[u] = true;
  while (cnt[u] < (int)g[u].size()) {
    cnt[u]++;
    if (mark[g[u][cnt[u] - 1].second])
      continue;
    else
      mark[g[u][cnt[u] - 1].second] = 1, Euler_path(g[u][cnt[u] - 1].first);
  }
  ans.push_back(u);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    reset();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(make_pair(v, i));
      g[v].push_back(make_pair(u, i));
      in[u]++;
      in[v]++;
      E.insert(make_pair(u, v));
      E.insert(make_pair(v, u));
    }
    int ctr = 0;
    for (int i = 0; i <= n; i++)
      if (in[i] % 2 == 0) ctr++;
    for (int i = 0; i < n + 1; i++)
      if (in[i] & 1) {
        g[i].push_back(make_pair(0, m));
        g[0].push_back(make_pair(i, m));
        ++m;
      }
    for (int i = 1; i <= n; i++)
      if (!visit[i]) {
        Euler_path(i);
        ans.push_back(i);
      }
    reverse(ans.begin(), ans.end());
    cout << ctr << endl;
    for (int i = 0; i < ans.size() - 1; i++) {
      if (E.find(make_pair(ans[i], ans[i + 1])) != E.end() or
          E.find(make_pair(ans[i + 1], ans[i])) != E.end())
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
  }
}
