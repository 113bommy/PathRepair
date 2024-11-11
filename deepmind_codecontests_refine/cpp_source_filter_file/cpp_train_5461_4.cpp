#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
const int maxn = 1e5;
int n, u, v, w, cnt, rt, tot, mn;
struct Edge {
  int to, next, w;
} e[maxn * 2 + 5];
int dep[maxn + 5], fa[maxn + 5], vis[maxn + 5], head[maxn + 5];
int mx[maxn + 5], col[maxn + 5], size[maxn + 5];
priority_queue<int, vector<int>, greater<int>> Q[maxn + 5];
set<pair<int, int>> all, S;
long long ans;
void add(int u, int v, int w) {
  e[++cnt] = (Edge){v, head[u], w}, head[u] = cnt;
  e[++cnt] = (Edge){u, head[v], w}, head[v] = cnt;
}
void findrt(int u, int par) {
  size[u] = 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == par) continue;
    findrt(v, u);
    chkmax(mx[u], size[v]);
    size[u] += size[v];
    ans += 1ll * min(size[v], n - size[v]) * e[i].w;
  }
  chkmax(mx[u], n - size[u]);
  if (chkmin(mn, mx[u])) mn = mx[u], rt = u;
}
int dfs(int u, int par, int k) {
  Q[col[u] = k].push(u);
  int size = 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == par) continue;
    dep[v] = dep[fa[v] = u] + e[i].w;
    size += dfs(v, u, k);
  }
  return size;
}
int main() {
  scanf("%d", &n);
  for (int i = (2); i <= int(n); i++) scanf("%d%d%d", &u, &v, &w), add(u, v, w);
  mn = 1e9, findrt(1, 1), printf("%lld\n", ans * 2);
  all.insert({rt, 0}), Q[0].push(rt), S.insert({size[0] = 2, 0});
  for (int i = head[rt]; i; i = e[i].next) {
    int v = e[i].to;
    tot++;
    S.insert({size[tot] = dfs(v, rt, tot) * 2, tot});
    all.insert({Q[tot].top(), tot});
  }
  for (int i = (1); i <= int(n); i++) {
    int up = n - i;
    pair<int, int> mx = *S.rbegin(), mx1 = *all.begin();
    if (mx.first > up && col[i] != mx.second && mx.second != rt) {
      int ans = Q[mx.second].top();
      S.erase({size[mx.second], mx.second});
      S.insert({--size[mx.second], mx.second});
      printf("%d ", ans);
      Q[mx.second].pop();
      all.erase({ans, mx.second});
      if (!Q[mx.second].empty()) all.insert({Q[mx.second].top(), mx.second});
    } else if (mx1.second == col[i] && i != rt) {
      all.erase(mx1);
      pair<int, int> mx2 = *all.begin();
      S.erase({size[mx2.second], mx2.second});
      S.insert({--size[mx2.second], mx2.second});
      printf("%d ", mx2.first);
      Q[mx2.second].pop();
      all.erase(mx2);
      if (!Q[mx2.second].empty()) all.insert({Q[mx2.second].top(), mx2.second});
      all.insert(mx1);
    } else {
      printf("%d ", mx1.first);
      S.erase({size[mx1.second], mx1.second});
      S.insert({--size[mx1.second], mx1.second});
      Q[mx1.second].pop();
      all.erase(mx1);
      if (!Q[mx1.second].empty()) all.insert({Q[mx1.second].top(), mx1.second});
    }
    S.erase({size[col[i]], col[i]});
    S.insert({--size[col[i]], col[i]});
  }
  return 0;
}
