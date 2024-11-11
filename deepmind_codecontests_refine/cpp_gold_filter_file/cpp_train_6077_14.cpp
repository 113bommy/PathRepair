#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long inf = 0x3f3f3f3f;
namespace FastIO {
template <typename tp>
inline void read(tp &x) {
  x = 0;
  register char c = getchar();
  register bool f = 0;
  for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar())
    ;
  if (f) x = -x;
}
template <typename tp>
inline void write(tp x) {
  if (x == 0) return (void)(putchar('0'));
  if (x < 0) putchar('-'), x = -x;
  long long pr[20];
  register long long cnt = 0;
  for (; x; x /= 10) pr[++cnt] = x % 10;
  while (cnt) putchar(pr[cnt--] + '0');
}
template <typename tp>
inline void writeln(tp x) {
  write(x);
  putchar('\n');
}
}  // namespace FastIO
using namespace FastIO;
int n, x[N];
vector<int> p[N];
int dp[N];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(x[i]);
    for (int j = 2; j <= sqrt(x[i]); j++)
      if (x[i] % j == 0) {
        p[i].push_back(j);
        if (j != x[i] / j) p[i].push_back(x[i] / j);
      }
    if (p[i].size() == 0) p[i].push_back(x[i]);
  }
  for (int i = 1; i <= n; i++) {
    int maxn = 0;
    for (int j = 0; j < p[i].size(); j++) {
      dp[p[i][j]]++;
      maxn = max(maxn, dp[p[i][j]]);
    }
    for (int j = 0; j < p[i].size(); j++) dp[p[i][j]] = maxn;
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) ans = max(ans, dp[i]);
  writeln(ans);
  return 0;
}
