#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
inline char gc() {
  return getchar();
  static const int maxs = 1 << 16;
  static char buf[maxs], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, maxs, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long rd() {
  long long x = 0;
  char c = gc();
  bool neg = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = 1;
    c = gc();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = gc();
  return neg ? (~x + 1) : x;
}
int N, M, Q;
char s[maxn][maxn];
bool mp[maxn][maxn];
int sum[maxn][maxn];
inline long long calc(int x, int y) {
  if (x < 0 || y < 0) return 0;
  long long re = (1ll * x * y - 1ll * (x % N) * (y % M)) / 2;
  int n = (x / N) ^ (y / M), m = 0;
  while (n) m += (n & 1), n >>= 1;
  if ((m & 1))
    re += (x % N) * (y % M) - sum[x % N][y % M];
  else
    re += sum[x % N][y % M];
  return re;
}
int main() {
  N = rd(), M = rd(), Q = rd();
  for (int i = 1; i <= N; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= M; j++) {
      mp[i][j] = (s[i][j] - '0');
      mp[i][j + M] = mp[i + N][j] = !mp[i][j];
      mp[i + N][j + M] = mp[i][j];
    }
  }
  N *= 2, M *= 2;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      sum[i][j] = mp[i][j] + (i ? sum[i - 1][j] : 0) + (j ? sum[i][j - 1] : 0) -
                  (i && j ? sum[i - 1][j - 1] : 0);
    }
  }
  for (int i = 1; i <= Q; i++) {
    int a = rd(), b = rd(), c = rd(), d = rd();
    if (N == 315) printf("%d %d %d %d\n", a, b, c, d);
    printf("%lld\n",
           calc(c, d) + calc(a - 1, b - 1) - calc(a - 1, d) - calc(c, b - 1));
  }
  return 0;
}
