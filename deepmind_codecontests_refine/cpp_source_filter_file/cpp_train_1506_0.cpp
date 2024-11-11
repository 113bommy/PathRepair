#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
const int P[2] = {1000000007, 1000000009};
int H[N], to[N], len[N], nxt[N], e = 1;
void addedge(int t, int v, int s) {
  e++, to[e] = v, len[e] = s, nxt[e] = H[t], H[t] = e;
  e++, to[e] = t, len[e] = s, nxt[e] = H[v], H[v] = e;
}
pair<unsigned long long, unsigned long long> Hash[N];
unsigned int val[N][64], cnt = 1;
int idx[N][64], tot = 1;
void calc_Hash(int k) {
  for (int i = 63; i >= 0; i--) {
    ((Hash[k].first <<= 32) += val[k][i]) %= P[0];
    ((Hash[k].second <<= 32) += val[k][i]) %= P[1];
  }
}
void init_() {
  for (int i = 0; i <= 63; i++) idx[1][i] = 1;
  for (int i = 0; i <= 63; i++) val[1][i] = -1;
  calc_Hash(1);
}
int cmp(int x, int y) {
  for (int i = 63; i >= 0; i--)
    if (Hash[idx[x][i]] != Hash[idx[y][i]])
      for (int j = 63; j >= 0; j--)
        if (val[idx[x][i]][j] != val[idx[y][i]][j])
          return val[idx[x][i]][j] < val[idx[y][i]][j] ? 1 : -1;
  return 0;
}
int add(int* x, int pos) {
  int* y = idx[++tot];
  for (int _ = 0; _ <= 63; _++) y[_] = x[_];
  int i = pos >> 11;
  int j = (pos >> 5) & 63;
  int k = pos & 31;
  y[i] = ++cnt;
  for (int _ = 0; _ <= 63; _++) val[y[i]][_] = val[x[i]][_];
  val[y[i]][j] += 1 << k;
  if (val[y[i]][j] < val[x[i]][j]) {
    while (++j < 64 && val[y[i]][j] == -1) val[y[i]][j]++;
    if (j != 64) val[y[i]][j]++;
  }
  calc_Hash(y[i]);
  if (j == 64) {
    while (Hash[y[++i]] == Hash[1]) y[i] = 0;
    y[i] = ++cnt;
    for (int _ = 0; _ <= 63; _++) val[y[i]][_] = val[x[i]][_];
    j = -1;
    while (++j < 64 && val[y[i]][j] == -1) val[y[i]][j]++;
    val[y[i]][j]++;
    calc_Hash(y[i]);
  }
  return tot;
}
struct comp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return cmp(a.first, b.first) == -1;
  }
};
int vis[N], pre[N], dis[N];
int main() {
  init_();
  int n, m;
  cin >> n >> m;
  while (m--) {
    int t, v, s;
    scanf("%d%d%d", &t, &v, &s);
    addedge(t, v, s);
  }
  int s, t;
  cin >> s >> t;
  for (int i = 1; i <= n; i++) dis[i] = 1;
  dis[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, comp> que;
  que.push(pair<int, int>(1, s));
  while (!que.empty()) {
    int u = que.top().second;
    que.pop();
    if (u == t) {
      unsigned long long ans = 0, mul = 1;
      for (int i = 63; i >= 0; i--) (mul <<= 31) %= P[0];
      for (int i = 63; i >= 0; i--)
        ((ans *= mul) += Hash[idx[dis[u]][i]].first) %= P[0];
      printf("%d\n", (int)ans);
      vector<int> vec;
      for (int v = t; v != s; v = pre[v]) vec.push_back(v);
      vec.push_back(s);
      printf("%d\n", vec.size());
      for (int i = (int)vec.size() - 1; i >= 0; i--) printf("%d ", vec[i]);
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = H[u], v = to[i]; i; i = nxt[i], v = to[i])
      if (!vis[v]) {
        int res = add(idx[dis[u]], len[i]);
        if (cmp(res, dis[v]) == 1) {
          dis[v] = res;
          que.push(pair<int, int>(dis[v], v));
          pre[v] = u;
        }
      }
  }
  puts("-1");
  return 0;
}
