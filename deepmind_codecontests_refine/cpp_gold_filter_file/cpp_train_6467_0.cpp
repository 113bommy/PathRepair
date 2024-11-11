#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 3e5 + 107;
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
template <typename T>
inline T powMM(T a, T b) {
  T ret = 1;
  for (; b; b >>= 1ll, a = (long long)a * a % M)
    if (b & 1) ret = (long long)ret * a % M;
  return ret;
}
int startTime;
void startTimer() { startTime = clock(); }
void printTimer() {
  fprintf(stderr, "/--- Time: %ld milliseconds ---/\n", clock() - startTime);
}
int n, m, q;
vector<int> edge[maxn];
long long downsum[maxn], sum[maxn];
int A[maxn];
long long ans = -INF;
int cnt;
void dfs1(int x, int fa) {
  downsum[x] = A[x];
  for (int v : edge[x])
    if (v != fa) {
      dfs1(v, x);
      downsum[x] += max(0ll, downsum[v]);
    }
  if (ans < downsum[x]) ans = downsum[x];
}
void dfs2(int x, int fa) {
  downsum[x] = A[x];
  for (int v : edge[x])
    if (v != fa) {
      dfs2(v, x);
      downsum[x] += max(0ll, downsum[v]);
    }
  if (downsum[x] == ans) cnt++, downsum[x] = 0;
}
int main() {
  int i;
  int MAX = -INF;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &A[i]), max_(MAX, A[i]);
  for (i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  printf("%lld %d\n", ans * cnt, cnt);
}
