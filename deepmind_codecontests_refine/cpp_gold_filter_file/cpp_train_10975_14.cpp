#include <bits/stdc++.h>
using namespace std;
inline int qr() {
  register int ret = 0, f = 0;
  register char c = getchar();
  while (!isdigit(c)) f |= c == 45, c = getchar();
  while (isdigit(c)) ret = ret * 10 + c - 48, c = getchar();
  return f ? -ret : ret;
}
const int maxn = 1e6 + 5;
char c[maxn];
int data[maxn];
int pre[maxn];
int n;
const int inf = 1e9;
inline void Jd() {
  int l = inf, r = -inf, pos = 0;
  for (int t = 1; t <= n; ++t) {
    l = min(pos, l);
    r = max(pos, r);
    if (data[t])
      --pos;
    else
      ++pos;
  }
  if (l > pos || r < pos) puts("1"), exit(0);
}
int main() {
  scanf("%s", c + 1);
  n = strlen(c + 1);
  for (int t = 1; t <= n; ++t) data[t] = (c[t] != 'L') ^ (c[n] == 'L');
  Jd();
  int Max = 0, pos = 0, ans = 1, End = 0, cur = 1;
  for (int t = 1; t <= n; ++t) {
    pre[t] = pos, Max = max(Max, pos);
    if (data[t])
      ++pos;
    else
      pos = max(pos - 1, 0);
  }
  if (Max >= pos) return puts("0"), 0;
  Max = 0;
  End = pos;
  while (cur <= n && (data[cur] || pre[cur])) Max = max(Max, pre[cur++]);
  while (cur <= n) {
    ++cur, ++Max;
    if (Max >= End) break;
    ++ans;
    while (cur <= n && (data[cur] || pre[cur])) Max = max(Max, pre[cur++]);
  }
  printf("%d\n", ans);
  return 0;
}
