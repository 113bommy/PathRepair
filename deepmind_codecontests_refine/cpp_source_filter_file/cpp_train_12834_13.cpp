#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
int n, m, k;
vector<int> e[maxn];
int vis[maxn], ru[maxn];
queue<int> q;
vector<int> s;
bool serch(int x, int y) {
  int l = 0, r = e[x].size();
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (e[x][mid] < y) {
      l = mid + 1;
    } else if (e[x][mid] == y) {
      return true;
    } else {
      r = mid - 1;
    }
  }
  return false;
}
bool check() {
  for (int x = 0; x < s.size(); x++) {
    for (int y = 0; y < s.size(); y++) {
      if (s[x] == s[y]) continue;
      if (!binary_search(e[x].begin(), e[x].end(), y)) return false;
    }
  }
  return true;
}
bool solve() {
  for (int i = 1; i <= n; i++) {
    ru[i] = e[i].size();
    if (ru[i] < k) {
      q.push(i);
      vis[i] = 1;
    }
  }
  while (!q.empty()) {
    int u = q.front();
    vis[u] = 2;
    q.pop();
    if (ru[u] == k - 1 && s.empty()) {
      s.push_back(u);
      for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (vis[v] != 2) s.push_back(v);
      }
      if (!check()) s.clear();
    }
    for (int i = 0; i < e[u].size(); i++) {
      ru[e[u][i]]--;
      if (ru[e[u][i]] < k && vis[e[u][i]] == 0) {
        q.push(e[u][i]);
        vis[e[u][i]] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) ans++;
  if (ans) {
    printf("1 %d\n", ans);
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        printf("%d ", i);
      }
    }
    puts("");
    return true;
  } else if (s.size()) {
    printf("2\n");
    for (int i = 0; i < s.size(); i++) {
      printf("%d ", s[i]);
    }
    puts("");
    return true;
  }
  return false;
}
void init() {
  s.clear();
  while (!q.empty()) q.pop();
  for (int i = 1; i <= n; i++) e[i].clear(), vis[i] = 0;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    sort(e[i].begin(), e[i].end());
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &m, &k);
    init();
    if (k * (k - 1) / 2 > m) {
      printf("-1\n");
      continue;
    }
    if (solve()) continue;
    printf("-1\n");
  }
}
