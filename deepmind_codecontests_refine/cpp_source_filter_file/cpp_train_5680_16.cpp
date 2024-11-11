#include <bits/stdc++.h>
using namespace std;
const int iinf = 0x7fffffff;
const long long linf = ~(1LL << 63);
template <typename T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long qpow(long long a, long long n, long long mod) {
  a %= mod;
  long long ans = 1LL;
  while (n) {
    if (n & 1) ans = (ans * a % mod);
    a = (a * a % mod);
    n >>= 1;
  }
  return ans;
}
inline long long rev(long long a, long long p) { return qpow(a, p - 2, p); }
inline int in() {
  int x;
  cin >> x;
  return x;
}
inline void tic() {}
inline void toc() {}
const int maxn = 150;
const int N = maxn;
const int M = 1000010;
const int INF = 0x7f7f7f7f;
struct Edge {
  int v, cap, cost, next;
  Edge() {}
  Edge(int a, int b, int c, int d) : v(a), cap(b), cost(c), next(d) {}
} e[M];
int head[N], sz;
int dis[N], pre[N], cur[N];
bool inq[N];
queue<int> q;
void graphinit() {
  for (int i = 0; i < N; i++) head[i] = -1;
  sz = 0;
}
void addedge(int u, int v, int cp, int ct) {
  e[sz] = Edge(v, cp, ct, head[u]);
  head[u] = sz++;
  e[sz] = Edge(u, 0, -ct, head[v]);
  head[v] = sz++;
}
pair<int, int> mcmf(int s, int t) {
  int mc = 0, mf = 0;
  while (true) {
    memset(pre, -1, sizeof(pre));
    memset(inq, 0, sizeof(inq));
    memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      inq[u] = false;
      for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].cap > 0 && dis[v] > dis[u] + e[i].cost) {
          dis[v] = dis[u] + e[i].cost;
          pre[v] = u;
          cur[v] = i;
          if (!inq[v]) {
            inq[v] = true;
            q.push(v);
          }
        }
      }
    }
    if (pre[t] == -1) break;
    int aug = INF;
    for (int i = t; i != s; i = pre[i]) aug = min(aug, e[cur[i]].cap);
    mf += aug;
    mc += dis[t] * aug;
    for (int i = t; i != s; i = pre[i]) {
      e[cur[i]].cap -= aug;
      e[cur[i] ^ 1].cap += aug;
    }
  }
  return make_pair(mf, mc);
}
int tot[maxn];
int main() {
  ios::sync_with_stdio(0);
  graphinit();
  int n, m, ans = 0;
  cin >> n >> m;
  addedge(n, 1, INF, 0);
  for (int i = 0; i < m; i++) {
    int u, v, c, f;
    cin >> u >> v >> c >> f;
    tot[u] -= f;
    tot[v] += f;
    if (f > c) {
      ans += f - c;
      addedge(v, u, f - c, 0);
      addedge(u, v, INF, 2);
      addedge(v, u, f, 1);
    } else {
      addedge(u, v, c - f, 1);
      addedge(u, v, INF, 2);
      addedge(v, u, f, 1);
    }
  }
  int s = 0, t = n + 1;
  for (int i = 1; i < n + 1; i++) {
    if (tot[i] > 0)
      addedge(s, i, tot[i], 0);
    else
      addedge(i, t, -tot[i], 0);
  }
  ans += mcmf(s, t).second;
  cout << ans << endl;
  return 0;
}
