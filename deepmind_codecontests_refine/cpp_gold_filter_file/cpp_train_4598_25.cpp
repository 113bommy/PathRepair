#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int INF = 1e9;
long long ans;
int n, m;
int A[maxn], pre[maxn], last[maxn], jud[maxn][2];
int read() {
  int x = 0, fl = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') fl = -1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x * fl;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) A[i] = read();
  for (int i = 1; i <= n; ++i) {
    if (!pre[A[i]]) pre[A[i]] = last[A[i]] = i;
    pre[A[i]] = min(pre[A[i]], i), last[A[i]] = max(last[A[i]], i);
  }
  int lastp = 0;
  for (int i = 1; i <= m; ++i) {
    if (!pre[i])
      jud[i][1] = 1;
    else if (pre[i] > last[lastp])
      lastp = i, jud[i][1] = 1;
    else
      break;
  }
  lastp = m + 1, pre[m + 1] = n + 1;
  jud[m + 1][2] = 1, jud[0][1] = 1;
  for (int i = m; i >= 1; --i) {
    if (!last[i])
      jud[i][2] = 1;
    else if (last[i] < pre[lastp])
      lastp = i, jud[i][2] = 1;
    else
      break;
  }
  int sum = 0;
  for (int i = 1; i <= m; ++i) last[i] = max(last[i - 1], last[i]);
  for (int i = m; i >= 1; --i)
    if (!pre[i]) pre[i] = pre[i + 1];
  int sp = 0;
  for (int i = 1; i <= m; ++i) {
    if (!jud[i + 1][2]) continue;
    while (jud[sp + 1][1] && sp + 2 <= i && last[sp + 1] < pre[i + 1]) ++sp;
    ans += sp + 1;
  }
  printf("%lld", ans);
  return 0;
}
