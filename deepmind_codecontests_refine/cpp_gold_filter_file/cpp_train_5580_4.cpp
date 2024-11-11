#include <bits/stdc++.h>
template <typename Tp>
void in(Tp &x) {
  char ch = getchar(), f = 1;
  x = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
template <typename Tp>
bool chkmax(Tp &x, Tp y) {
  return x > y ? 0 : (x = y, 1);
}
template <typename Tp>
bool chkmin(Tp &x, Tp y) {
  return x < y ? 0 : (x = y, 1);
}
template <typename Tp>
Tp Max(Tp x, Tp y) {
  return x > y ? x : y;
}
template <typename Tp>
Tp Min(Tp x, Tp y) {
  return x < y ? x : y;
}
namespace __pyh_dinic {
const int MAXN = 110, MAXM = 100010;
const int ss = 0, tt = 105;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
using std::queue;
struct Dinic_graph {
  queue<int> q;
  long long flow[MAXM];
  int cnt;
  int head[MAXN], data[MAXM], nxt[MAXM], cur[MAXN];
  int dis[MAXN];
  void clear() {
    cnt = 0;
    memset(head, -1, sizeof head);
  }
  void add(int x, int y, long long z) {
    nxt[cnt] = head[x];
    data[cnt] = y;
    flow[cnt] = z;
    head[x] = cnt++;
    nxt[cnt] = head[y];
    data[cnt] = x;
    flow[cnt] = 0;
    head[y] = cnt++;
  }
  bool bfs() {
    memset(dis, -1, sizeof dis);
    dis[ss] = 0;
    q.push(ss);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int i = head[now]; i != -1; i = nxt[i]) {
        if (flow[i] && dis[data[i]] == -1) {
          dis[data[i]] = dis[now] + 1;
          q.push(data[i]);
        }
      }
    }
    return dis[tt] != -1;
  }
  long long dfs(int now, long long fl) {
    long long ret = 0;
    if (now == tt) return fl;
    for (int &i = cur[now]; i != -1; i = nxt[i]) {
      if (!flow[i] || dis[data[i]] != dis[now] + 1) continue;
      if (ret = dfs(data[i], Min(fl, flow[i]))) {
        flow[i] -= ret;
        flow[i ^ 1] += ret;
        return ret;
      }
    }
    return 0;
  }
  long long dinic(void) {
    long long ret = 0;
    while (bfs()) {
      long long fl;
      memcpy(cur, head, sizeof head);
      while (fl = dfs(ss, inf)) ret += fl;
    }
    return ret;
  }
} G;
}  // namespace __pyh_dinic
using namespace __pyh_dinic;
int n, nd;
int p[MAXN], c[MAXN], lv[MAXN];
bool no_prime[200010];
int prime[200010];
void prework() {
  for (int i = (2), i_END_ = (200000); i <= i_END_; i++) {
    if (!no_prime[i]) prime[++prime[0]] = i;
    for (int j = 1; prime[j] * i <= 200000; j++) {
      no_prime[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
bool judge(int x) {
  G.clear();
  int maxx = 0, pos = 0;
  long long sum = 0;
  for (int i = (1), i_END_ = (n); i <= i_END_; i++)
    if (c[i] != 1 && lv[i] <= x) {
      if (c[i] & 1)
        G.add(ss, i, p[i]);
      else
        G.add(i, tt, p[i]);
      sum += p[i];
    }
  for (int i = (1), i_END_ = (n); i <= i_END_; i++)
    if (c[i] == 1 && lv[i] <= x)
      if (chkmax(maxx, p[i])) pos = i;
  for (int i = (1), i_END_ = (n); i <= i_END_; i++)
    if ((c[i] & 1) && lv[i] <= x) {
      if (c[i] == 1) continue;
      for (int j = (1), j_END_ = (n); j <= j_END_; j++)
        if (!no_prime[c[i] + c[j]] && lv[i] <= x) G.add(i, j, inf);
    }
  if (pos) {
    G.add(ss, pos, p[pos]);
    sum += p[pos];
    for (int i = (1), i_END_ = (n); i <= i_END_; i++)
      if (c[i] != 1 && !no_prime[c[i] + 1]) G.add(pos, i, inf);
  }
  return sum - G.dinic() >= nd;
}
void binary() {
  int l = 1, r = 1, ans = -1;
  for (int i = (1), i_END_ = (n); i <= i_END_; i++) chkmax(r, lv[i]);
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (judge(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
}
int main() {
  in(n);
  in(nd);
  for (int i = (1), i_END_ = (n); i <= i_END_; i++)
    in(p[i]), in(c[i]), in(lv[i]);
  prework();
  binary();
  return 0;
}
