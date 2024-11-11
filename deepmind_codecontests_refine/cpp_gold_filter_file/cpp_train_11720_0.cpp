#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 100;
int f[MAX_N];
int tr[MAX_N], u[MAX_N], v[MAX_N];
vector<int> G[MAX_N], GG[MAX_N];
int cnt[MAX_N];
int color[MAX_N];
int n;
void init() {
  for (int i = 1; i <= n; i++) {
    f[i] = i;
    tr[i] = i;
  }
}
int find(int x) {
  int t;
  if (f[x] == x) return x;
  t = find(f[x]);
  return t;
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return;
  f[fx] = fy;
}
void dfs(int u, int fa) {
  if (fa != -1 && color[u] == color[fa]) {
    merge(u, fa);
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      dfs(v, u);
    }
  }
}
int main() {
  scanf("%d", &n);
  init();
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &u[i], &v[i]);
    G[u[i]].push_back(v[i]);
    G[v[i]].push_back(u[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &color[i]);
    cnt[color[i]] = 1;
  }
  int sum = 0;
  for (int i = 1; i <= MAX_N; i++) {
    sum += cnt[i];
  }
  if (n == 2 || sum == 1) {
    printf("YES\n1\n");
    return 0;
  }
  dfs(1, -1);
  bool flag = true;
  for (int i = 0; i < n - 1; i++) {
    int fa = find(u[i]), fb = find(v[i]);
    if (color[fa] != color[fb]) {
      GG[fa].push_back(fb);
      GG[fb].push_back(fa);
    }
  }
  int r = -1;
  for (int i = 1; i <= n; i++) {
    if (GG[i].size() == 1) {
      if (r == -1)
        r = GG[i][0];
      else if (r != GG[i][0]) {
        flag = false;
        break;
      }
    }
  }
  int s = 0;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    int x = find(i);
    cnt[x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    s += cnt[i];
  }
  if (s == 2) flag = true;
  if (!flag) {
    puts("NO");
  } else {
    int ans = -1;
    for (int i = 0; i < n - 1; i++) {
      if (find(u[i]) == r) {
        if (color[u[i]] != color[v[i]]) {
          if (ans == -1)
            ans = u[i];
          else if (ans != u[i]) {
            flag = false;
            break;
          }
        }
      }
      if (find(v[i]) == r) {
        if (color[u[i]] != color[v[i]]) {
          if (ans == -1)
            ans = v[i];
          else if (ans != v[i]) {
            flag = false;
            break;
          }
        }
      }
    }
    if (!flag || ans == -1)
      puts("NO");
    else {
      puts("YES");
      printf("%d\n", ans);
    }
  }
  return 0;
}
