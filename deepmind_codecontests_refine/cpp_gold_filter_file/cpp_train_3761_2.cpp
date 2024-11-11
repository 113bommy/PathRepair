#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1e6 + 107;
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
int n, len;
char s[maxn], a[maxn], b[maxn];
char toward[255];
bool used[255], okay;
void dfs(int pos, bool issmaller, bool isbetter) {
  if (okay) return;
  int i, j;
  if (pos == len) {
    okay = 1;
    puts("YES");
    for (i = 0; i < n; i++)
      if (!toward[i + 'a']) {
        for (j = 0; j < n; j++)
          if (!used[j + 'a']) {
            toward[i + 'a'] = j + 'a';
            used[j + 'a'] = 1;
            break;
          }
      }
    puts(toward + 'a');
    return;
  }
  if (toward[(int)s[pos]]) {
    if ((issmaller || toward[(int)s[pos]] <= a[pos]) &&
        (isbetter || b[pos] <= toward[(int)s[pos]]))
      dfs(pos + 1, issmaller || toward[(int)s[pos]] < a[pos],
          isbetter || toward[(int)s[pos]] > b[pos]);
  } else {
    for (i = 'a'; i < 'a' + n; i++)
      if (!used[i]) {
        toward[(int)s[pos]] = i;
        used[i] = 1;
        if ((issmaller || toward[(int)s[pos]] <= a[pos]) &&
            (isbetter || b[pos] <= toward[(int)s[pos]]))
          dfs(pos + 1, issmaller || toward[(int)s[pos]] < a[pos],
              isbetter || toward[(int)s[pos]] > b[pos]);
        if (okay) return;
        toward[(int)s[pos]] = 0;
        used[i] = 0;
      }
  }
}
void solve() {
  int i;
  scanf("%d", &n);
  scanf("%s%s%s", s, b, a);
  for (i = 0; i < n + 1; i++) toward[i + 'a'] = used[i + 'a'] = 0;
  len = strlen(s);
  okay = 0;
  dfs(0, 0, 0);
  if (!okay) puts("NO");
}
int main() {
  int T, _;
  scanf("%d", &T);
  for (_ = 1; _ <= T; _++) solve();
}
