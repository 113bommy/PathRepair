#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long inf = 0x3f3f3f3f;
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline long long gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long ret = 0, f = 0;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = gc();
  }
  while (isdigit(c)) {
    ret = ret * 10 + c - 48;
    c = gc();
  }
  if (f) return -ret;
  return ret;
}
long long dp[30][30];
long long cnt[30];
char s[100005];
int32_t main() {
  scanf("%s", s + 1);
  long long len = strlen(s + 1);
  long long ans = 0;
  for (long long i = (1); i <= (len); i++) {
    for (long long j = (1); j <= (26); j++) {
      dp[s[i] - 'a' + 1][j] += cnt[j];
      ans = max(ans, dp[s[i] - 'a' + 1][j]);
    }
    cnt[s[i] - 'a' + 1]++;
    ans = max(ans, cnt[s[i] - 'a' + 1]);
  }
  printf("%lld\n", ans);
  return 0;
}
