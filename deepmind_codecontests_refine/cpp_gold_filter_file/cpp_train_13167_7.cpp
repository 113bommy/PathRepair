#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
const int maxm = 1010;
const int maxs = 26;
const int inf = 0x3f3f3f3f;
const int P = 1000000007;
const double error = 1e-9;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
struct edge {
  int u, v;
  long long w;
  int next, pos;
} e[2 * maxn];
int n, m, s, cnt, head[maxn], vis[maxn], fa[maxn];
long long ans, dis[maxn];
void insert(int u, int v, long long w, int pos) {
  e[cnt] = (edge){u, v, w, head[u], pos}, head[u] = cnt++;
  e[cnt] = (edge){v, u, w, head[v], pos}, head[v] = cnt++;
}
void spfa() {
  for (int i = 1; i <= n; i++) dis[i] = (long long)inf * inf;
  queue<int> q;
  q.push(s), dis[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (int i = head[u]; i != -1; i = e[i].next) {
      int v = e[i].v;
      if (dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        if (!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
}
bool cmp(edge a, edge b) {
  long long disa = max(dis[a.u], dis[a.v]);
  long long disb = max(dis[b.u], dis[b.v]);
  return disa < disb || disa == disb && a.w < b.w;
}
int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
vector<int> num;
int main() {
  n = read(), m = read();
  memset(head, -1, sizeof head);
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    long long w = read();
    insert(u, v, w, i);
  }
  s = read(), spfa();
  sort(e, e + cnt, cmp);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 0; i < cnt; i++) {
    int u = e[i].u, v = e[i].v;
    if (abs(dis[u] - dis[v]) == e[i].w) {
      int fu = find(u), fv = find(v);
      if (fu != fv) {
        ans += e[i].w, fa[fu] = fv;
        num.push_back(e[i].pos);
      }
    }
  }
  printf("%I64d\n", ans);
  for (int i = 0; i < num.size(); i++) printf("%d ", num[i]);
  return 0;
}
