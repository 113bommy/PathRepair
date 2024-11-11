#include <bits/stdc++.h>
using namespace std;
int n, cnt[8888], fail[8888], tlen, dp[8888];
char s[8005], t[8005];
inline void getlen(int x) {
  int tx = x;
  while (tx) {
    ++cnt[x];
    tx /= 10;
  }
}
inline void init() {
  for (int i = 0; i < 8888; ++i) getlen(i);
}
inline void getNext() {
  int j = 0, k = -1;
  fail[0] = -1;
  while (j < tlen)
    if (k == -1 || t[j] == t[k])
      fail[++j] = ++k;
    else
      k = fail[k];
}
inline int getcir(int x) {
  if (x % (x - fail[x]) != 0) return x;
  return x - fail[x];
}
int main() {
  init();
  scanf("%s", s + 1);
  n = strlen(s + 1);
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for (int i = 0; i <= n; ++i) {
    memset(t, 0, sizeof t);
    memcpy(t, s + i + 1, (n - i + 1) * sizeof s[0]);
    tlen = strlen(t);
    getNext();
    for (int j = i + 1; j <= n; ++j)
      dp[j] = min(dp[j], dp[i] + getcir(j - i) + cnt[tlen / getcir(j - i)]);
  }
  printf("%d\n", dp[n]);
  return 0;
}
