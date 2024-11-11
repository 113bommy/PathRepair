#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXM = 50000007;
const long long INF = 0x3f3f3f3f3f3f3f3f;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int Q, ans[MAXN];
struct Query {
  long long n, k;
  int id;
  bool operator<(const Query &rhs) const { return k < rhs.k; }
} q[MAXN];
int pr[MAXM], pcnt, pfac[MAXN], tot;
bool notp[MAXM];
void sieve(int m) {
  for (int i = 2; i <= m; ++i) {
    if (!notp[i]) {
      pr[++pcnt] = i;
    }
    for (int j = 1; j <= pcnt && i * pr[j] <= m; ++j) {
      notp[i * pr[j]] = 1;
      if (i % pr[j] == 0) break;
    }
  }
}
void extend_gcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  extend_gcd(b, a % b, y, x);
  y -= a / b * x;
}
long long dis[MAXN];
bool vis[MAXN];
priority_queue<pair<long long, int> > pq;
void Dijkstra(int p) {
  for (int i = 0; i < p; ++i) {
    dis[i] = INF;
    vis[i] = 0;
  }
  dis[0] = 0;
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = 2; i <= tot; ++i) {
      int v = (pfac[i] + u) % p;
      if (dis[v] > dis[u] + pfac[i]) {
        dis[v] = dis[u] + pfac[i];
        pq.push(make_pair(-dis[v], v));
      }
    }
  }
}
void init() {
  sieve(50000000);
  read(Q);
  for (int i = 1; i <= Q; ++i) {
    read(q[i].n);
    read(q[i].k);
    q[i].id = i;
  }
  sort(q + 1, q + Q + 1);
}
void solve() {
  for (int i = 1, j = 1; i <= Q; i = j + 1) {
    for (j = i; j + 1 <= Q && q[j + 1].k == q[i].k; ++j)
      ;
    long long tmp = q[i].k;
    tot = 0;
    for (int t = 1; t <= pcnt && 1LL * pr[t] * pr[t] <= tmp; ++t) {
      if (tmp % pr[t]) continue;
      pfac[++tot] = pr[t];
      while (tmp % pr[t] == 0) {
        tmp /= pr[t];
      }
    }
    if (tmp > 1) {
      pfac[++tot] = tmp;
    }
    if (tot == 1) {
      for (int t = i; t <= j; ++t) {
        ans[q[t].id] = (q[t].n % q[t].k == 0);
      }
    } else if (tot == 2) {
      long long x, y;
      extend_gcd(pfac[1], pfac[2], x, y);
      long long ia = (x + pfac[2]) % pfac[2];
      for (int t = i; t <= j; ++t) {
        ans[q[t].id] = (pfac[1] * (q[t].n % pfac[2] * ia % pfac[2]) <= q[t].n);
      }
    } else if (tot >= 3) {
      Dijkstra(pfac[1]);
      for (int t = i; t <= j; ++t) {
        ans[q[t].id] = (dis[q[t].n % pfac[1]] <= q[t].n);
      }
    }
  }
  for (int i = 1; i <= Q; ++i) {
    puts(ans[i] ? "YES" : "NO");
  }
}
int main() {
  init();
  solve();
  return 0;
}
