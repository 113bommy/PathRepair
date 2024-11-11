#include <bits/stdc++.h>
using namespace std;
int read() {
  int s = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * t;
}
int n, m;
char ch[100010];
int main() {
  n = read(), m = read();
  scanf("%s", ch + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (ch[i] != ch[i - 1]) ans += 1ll * n * (m - 1);
  for (int i = 1, j = 1; i < n; i = j - 1) {
    if (ch[i] != ch[i + 1]) {
      for (j = i + 2; j <= n && ch[j] == ch[j - 2]; j++)
        ;
      int len = j - i;
      ans -= 1ll * len * (len - 1) / 2;
    } else
      j++;
  }
  printf("%lld\n", ans);
  return 0;
}
