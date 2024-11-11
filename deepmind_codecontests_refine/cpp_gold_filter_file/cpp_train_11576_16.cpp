#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 998244353;
const long long maxn = 2e5 + 107;
const double pi = acos(-1.0);
const double eps = 0.0000000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline void pr2(T x, int k = 64) {
  long long i;
  for (i = 0; i < k; i++) fprintf(stderr, "%d", (x >> i) & 1);
  putchar(' ');
}
template <typename T>
inline void add_(T &A, int B, long long MOD = M) {
  A += B;
  (A >= MOD) && (A -= MOD);
}
template <typename T>
inline void mul_(T &A, long long B, long long MOD = M) {
  A = (A * B) % MOD;
}
template <typename T>
inline void mod_(T &A, long long MOD = M) {
  A %= MOD;
  A += MOD;
  A %= MOD;
}
template <typename T>
inline void max_(T &A, T B) {
  (A < B) && (A = B);
}
template <typename T>
inline void min_(T &A, T B) {
  (A > B) && (A = B);
}
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
inline long long powMM(long long a, long long b, long long mod = M) {
  long long ret = 1;
  for (; b; b >>= 1ll, a = a * a % mod)
    if (b & 1) ret = ret * a % mod;
  return ret;
}
int startTime;
void startTimer() { startTime = clock(); }
void printTimer() {
  fprintf(stderr, "/--- Time: %ld milliseconds ---/\n", clock() - startTime);
}
int ans[maxn], nowans;
struct node {
  int l, r, u, v, id, val;
};
int fa[maxn];
vector<node> edge[27];
vector<pair<int, int> > nodes[27];
inline int getfa(int x, int depth) {
  if (fa[x] == x) return fa[x];
  int y = getfa(fa[x], depth);
  nodes[depth].push_back(make_pair(x, fa[x]));
  if (fa[x] != y) fa[x] = y;
  return fa[x];
}
int n;
int Q[maxn][3], use[maxn][2];
map<pair<int, int>, int> MP;
void solve(int dep, int l, int r) {
  for (auto e : edge[dep]) {
    if (e.l <= l && r <= e.r) {
      if (!use[e.id][e.val]) continue;
      int x = getfa(e.u, dep), y = getfa(e.v, dep);
      if (x != y) {
        nodes[dep].push_back(make_pair(x, x));
        fa[x] = y;
      }
    }
  }
  if (l == r) {
    int u, v, op, x, y, o;
    op = Q[l][0];
    u = Q[l][1];
    v = Q[l][2];
    if (op == 2) {
      u = (u + nowans - 1) % n + 1;
      v = (v + nowans - 1) % n + 1;
      nowans = (getfa(u, dep) == getfa(v, dep));
      printf("%d", nowans);
      ans[l] = nowans;
    } else {
      x = (u + nowans - 1) % n + 1;
      y = (v + nowans - 1) % n + 1;
      if (x > y) swap(x, y);
      MP[make_pair(x, y)] ^= 1;
      for (o = 0; o < 2; o++) {
        x = u;
        y = v;
        if (x > y) swap(x, y);
        use[l][0] = MP[make_pair(x, y)];
        x = u % n + 1;
        y = v % n + 1;
        if (x > y) swap(x, y);
        use[l][1] = MP[make_pair(x, y)];
      }
    }
  } else {
    for (auto e : edge[dep]) {
      getfa(e.u, dep);
      getfa(e.v, dep);
    }
    int mid = (l + r) / 2;
    edge[dep + 1].clear();
    nodes[dep + 1].clear();
    for (auto e : edge[dep]) {
      if (e.l <= l && r <= e.r) continue;
      if (e.l <= mid) edge[dep + 1].push_back(e);
    }
    solve(dep + 1, l, mid);
    edge[dep + 1].clear();
    nodes[dep + 1].clear();
    for (auto e : edge[dep]) {
      if (e.l <= l && r <= e.r) continue;
      if (mid < e.r) edge[dep + 1].push_back(e);
    }
    solve(dep + 1, mid + 1, r);
  }
  reverse(nodes[dep].begin(), nodes[dep].end());
  for (auto x : nodes[dep]) fa[x.first] = x.second;
}
int main() {
  int m, i, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) fa[i] = i;
  for (i = 1; i <= m; i++)
    for (k = 0; k < 3; k++) scanf("%d", &Q[i][k]);
  for (i = m; i >= 1; i--) {
    int u, v, x, y, op, pre;
    op = Q[i][0];
    u = Q[i][1];
    v = Q[i][2];
    if (op == 1) {
      x = u;
      y = v;
      if (x > y) swap(x, y);
      pre = MP[make_pair(x, y)];
      if (!pre) pre = m;
      MP[make_pair(x, y)] = i;
      edge[1].push_back(node{i + 1, pre, x, y, i, 0});
      x = u % n + 1;
      y = v % n + 1;
      if (x > y) swap(x, y);
      pre = MP[make_pair(x, y)];
      if (!pre) pre = m;
      if (pre == i) continue;
      MP[make_pair(x, y)] = i;
      edge[1].push_back(node{i + 1, pre, x, y, i, 1});
    } else
      continue;
  }
  MP.clear();
  solve(1, 1, m);
}
