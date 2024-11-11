#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, o = 1;
  register char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = ((x << 3) + (x << 1)) + ch - '0', ch = getchar();
  return x * o;
}
int n, s[101000][30], sum[101000];
long long ans;
char t[101000];
map<int, int> M;
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i) {
    scanf("%s", t + 1);
    int len = strlen(t + 1);
    for (register int j = 1; j <= len; ++j) s[i][t[j] - 'a'] ^= 1;
    for (register int j = 0; j < 26; ++j)
      if (s[i][j]) sum[i] |= (1 << j);
    ans += M[sum[i]];
    for (register int j = 0; j < 26; ++j) ans += M[sum[i] ^ (1 << j)];
    ++M[sum[i]];
  }
  printf("%I64d\n", ans);
}
