#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxm = 25;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
int n, m, d;
int belong[maxn];
int cnt[maxm];
bool bad[1 << 20];
int get_cnt(int x) {
  int ret = 0;
  while (x) {
    if (x & 1) ret++;
    x >>= 1;
  }
  return ret;
}
int main() {
  n = read(), m = read(), d = read();
  for (int i = 1; i <= m; i++)
    for (int j = read(); j; j--) belong[read()] = i;
  for (int i = 1; i <= n; i++) {
    if (i > d) cnt[belong[i - d]]--;
    cnt[belong[i]]++;
    if (i >= d) {
      int state = 0;
      for (int j = 1; j <= m; j++)
        if (!cnt[j]) state |= (1 << (j - 1));
      bad[state] = 1;
    }
  }
  int ans = m + 1;
  for (int i = (1 << m) - 1; i; i--)
    if (bad[i]) {
      for (int j = 1; j <= m; j++)
        if (i & (1 << (j - 1))) bad[i ^ (i << (j - 1))] = 1;
    } else
      ans = min(ans, get_cnt(i));
  printf("%d\n", ans);
  return 0;
}
