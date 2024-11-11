#include <bits/stdc++.h>
using namespace std;
int T, n, m, deg[500010], s[500010], e[500010];
bool vis[500010];
vector<int> v[500010];
inline int cmp(int x, int y) { return deg[x] % 3 < deg[y] % 3; }
vector<int> ans;
int fa[500010];
int col[500010], dep[500010];
bool tag[500010];
bool dfs3(int np, int fath) {
  for (int &x : v[np]) {
    if (x == fath) continue;
    if (deg[x] % 3 == 2) {
      if (tag[x]) {
        vis[np] = vis[x] = 1;
        return 1;
      }
      if (dfs3(x, np)) {
        vis[np] = 1;
        return 1;
      }
    }
  }
  return 0;
}
bool dfs4(int np, int fath) {
  col[np] = 1;
  fa[np] = fath;
  dep[np] = dep[fath] + 1;
  int id = 0;
  for (auto &x : v[np]) {
    if (x != fath && deg[x] % 3 == 2 && col[x] && (!id || dep[x] > dep[id]))
      id = x;
  }
  if (id) {
    vis[id] = 1;
    for (int j = np; j != id; j = fa[j]) vis[j] = 1;
    return 1;
  }
  for (auto &x : v[np]) {
    if (x != fath && deg[x] % 3 == 2 && !col[x]) {
      if (dfs4(x, np)) return 1;
    }
  }
  return 0;
}
queue<int> q;
inline void solve() {
  scanf("%d%d", &n, &m);
  fill(deg + 1, deg + n + 1, 0);
  fill(vis + 1, vis + n + 1, 0);
  fill(col + 1, col + n + 1, 0);
  fill(dep + 1, dep + n + 1, 0);
  fill(tag + 1, tag + n + 1, 0);
  for (int i = 1; i <= n; i++) v[i].clear();
  ans.clear();
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &s[i], &e[i]);
    deg[s[i]]++;
    deg[e[i]]++;
    v[s[i]].push_back(e[i]);
    v[e[i]].push_back(s[i]);
  }
  if (n == 1) {
    puts("No");
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] % 3 == 0) {
      puts("Yes");
      printf("%d\n", n - 1);
      for (int j = 1; j <= n; j++)
        if (j != i) printf("%d ", j);
      puts("");
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] % 3 == 2 && !col[i]) {
      if (dfs4(i, 0)) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
          if (!vis[j]) cnt++;
        }
        if (!cnt)
          puts("No");
        else {
          puts("Yes");
          printf("%d\n", cnt);
          for (int j = 1; j <= n; j++)
            if (!vis[j]) printf("%d ", j);
          puts("");
        }
        return;
      }
    }
  }
  fill(vis + 1, vis + n + 1, 0);
  fill(col + 1, col + n + 1, 0);
  int cnt1 = 0;
  for (int i = 1; i <= n; i++)
    if (deg[i] % 3 == 1) cnt1++;
  for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
  if (cnt1 >= 2) {
    int ed, st;
    fill(fa + 1, fa + n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (deg[i] % 3 == 1) {
        st = i;
        q.push(i);
        col[i] = 1;
        break;
      }
    }
    while (!q.empty()) {
      int fr = q.front();
      q.pop();
      if (deg[fr] % 3 == 1 && fr != st) {
        ed = fr;
        break;
      }
      for (auto &x : v[fr]) {
        if (!col[x]) {
          fa[x] = fr;
          col[x] = 1;
          q.push(x);
        }
      }
    }
    while (!q.empty()) q.pop();
    for (int i = ed; i; i = fa[i]) vis[i] = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) cnt++;
    if (!cnt)
      puts("No");
    else {
      printf("Yes\n%d\n", cnt);
      for (int i = 1; i <= n; i++)
        if (!vis[i]) printf("%d ", i);
      puts("");
    }
  } else {
    int pos = 0;
    for (int i = 1; i <= n; i++) {
      if (deg[i] % 3 == 1) {
        pos = i;
        break;
      }
    }
    for (auto &x : v[pos]) tag[x] = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (tag[i] && !col[i]) {
        dfs4(i, 0);
        dfs3(i, 0);
        cnt++;
        if (cnt == 2) break;
      }
    }
    vis[pos] = 1;
    cnt = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) cnt++;
    if (!cnt)
      puts("No");
    else {
      puts("Yes");
      printf("%d\n", cnt);
      for (int i = 1; i <= n; i++)
        if (!vis[i]) printf("%d ", i);
      puts("");
    }
  }
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
