#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> G[N];
int vis[N];
int cons[N][2];
int cont[N][2];
int const1[N][3];
vector<pair<int, int> > ans;
int cnt;
int s, t;
void dfs(int u) {
  vis[u] = cnt;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!vis[v] && v != s && v != t) {
      ans.push_back(make_pair(u, v));
      dfs(v);
    }
  }
}
int main() {
  int n, m, degs, degt;
  cin >> n >> m;
  int u, v;
  int cnt1 = 0;
  int flag = 0;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cin >> s >> t >> degs >> degt;
  for (int i = 1; i <= n; i++)
    if (!vis[i] && i != s && i != t) {
      cnt++;
      dfs(i);
    }
  int x;
  for (int i = 0; i < G[s].size(); i++) {
    x = G[s][i];
    if (cons[vis[x]][0] == 0) {
      cons[vis[x]][0]++;
      cons[vis[x]][1] = x;
    }
  }
  for (int i = 0; i < G[t].size(); i++) {
    x = G[t][i];
    if (cont[vis[x]][0] == 0) {
      cont[vis[x]][0]++;
      cont[vis[x]][1] = x;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (cons[i][0] == 1 && cont[i][0] == 1) {
      cnt1++;
      cons[i][0] = 0;
      cont[i][0] = 0;
      const1[i][0]++;
      const1[i][1] = cons[i][1];
      const1[i][2] = cont[i][1];
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (cons[i][0]) {
      ans.push_back(make_pair(s, cons[i][1]));
      degs--;
    }
    if (cont[i][0]) {
      ans.push_back(make_pair(t, cont[i][1]));
      degt--;
    }
  }
  if (degs <= 0 || degt <= 0) {
    cout << "No0" << endl;
    return 0;
  }
  if (cons[0][0] && degs + degt - 2 >= cnt1) {
    ans.push_back(make_pair(s, t));
    degs--, degt--;
    for (int i = 1; i <= cnt; ++i) {
      if (degs > 0 && const1[i][0] == 1) {
        ans.push_back(make_pair(s, const1[i][1]));
        degs--;
      } else if (degt > 0 && const1[i][0] == 1) {
        ans.push_back(make_pair(t, const1[i][2]));
        degt--;
      }
    }
    printf("Yes\n");
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
  }
  if (cnt1 >= 1 && degs + degt - 2 >= cnt1 - 1) {
    for (int i = 1; i <= cnt; ++i) {
      if (degs > 0 && degt > 0 && const1[i][0] == 1) {
        ans.push_back(make_pair(s, const1[i][1]));
        ans.push_back(make_pair(t, const1[i][2]));
        degs--, degt--;
        const1[i][0] = 0;
        break;
      }
    }
    for (int i = 1; i <= cnt; ++i) {
      if (degs > 0 && const1[i][0] == 1) {
        ans.push_back(make_pair(s, const1[i][1]));
        degs--;
      } else if (degt > 0 && const1[i][0] == 1) {
        ans.push_back(make_pair(t, const1[i][2]));
        degt--;
      }
    }
    printf("Yes\n");
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
  }
  return 0 * printf("No1\n");
  return 0;
}
