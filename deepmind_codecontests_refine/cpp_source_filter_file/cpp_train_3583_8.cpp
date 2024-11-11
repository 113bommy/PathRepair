#include <bits/stdc++.h>
using namespace std;
int n, s[105], m, t[105], dp[1 << 20];
char buf[3];
bool p[105];
bool cmp(int a, int b) { return a > b; }
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%d", &s[i]);
  sort(s, s + n, cmp);
  scanf("%d", &m);
  for (int i = (0); i < (m); i++) {
    scanf("%s %d", buf, &t[i]);
    p[i] = buf[0] == 'p';
  }
  for (int i = (1); i < (1 << m); i++) {
    dp[i] = -1e9;
    int x = m - __builtin_popcount(i);
    for (int j = (0); j < (m); j++)
      if (i & 1 << j) {
        if (t[x] != t[x + 1])
          dp[i] = max(dp[i], -dp[(i | 1) << j] + p[x] * s[j]);
        else
          dp[i] = max(dp[i], dp[(i | 1) << j] + p[x] * s[j]);
      }
  }
  printf("%d\n", t[0] == 1 ? dp[(1 << m) - 1] : -dp[(1 << m) - 1]);
}
