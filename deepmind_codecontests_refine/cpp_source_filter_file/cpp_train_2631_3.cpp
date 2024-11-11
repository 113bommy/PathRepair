#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1.5e6 + 107;
const double pi = acos(-1.0);
const double eps = 1e-7;
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
vector<pair<int, int> > v[maxn];
int fa[maxn], sz[maxn], cnt[maxn];
int C[1607][1607];
inline int getfa(int x) {
  if (fa[x] == x) return x;
  return fa[x] = getfa(fa[x]);
}
int tmp[maxn];
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      int val;
      scanf("%d", &val);
      v[val].push_back(make_pair(i, j));
    }
  }
  for (i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
  for (i = 0; i <= n * n / 2; i++) {
    for (auto now : v[i]) {
      int x = now.first, y = now.second;
      x = getfa(x);
      y = getfa(y);
      if (x != y) {
        int j, k;
        for (j = 1; j <= sz[x] + sz[y]; j++) tmp[j] = 0;
        for (j = 1; j <= sz[x]; j++)
          for (k = 1; k <= sz[y]; k++) {
            add_(tmp[j + k], (long long)C[x][j] * C[y][k] % M);
          }
        for (j = 1; j <= sz[x] + sz[y]; j++) C[y][j] = tmp[j];
        fa[x] = y;
        sz[y] += sz[x];
        cnt[y] += cnt[x];
      }
      x = getfa(x);
      cnt[x]++;
      if (cnt[x] == sz[x] * sz[x]) C[x][1]++;
    }
  }
  int x = getfa(1);
  for (i = 1; i <= n; i++) printf("%d%c", C[x][i], " \n"[i == n]);
}
