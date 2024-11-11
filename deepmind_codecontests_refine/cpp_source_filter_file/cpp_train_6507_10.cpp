#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
const int MAXN = 1010;
char s[MAXN][MAXN];
int len[MAXN];
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tot = 0, maxlen = 0;
  while (gets(s[++tot] + 1))
    maxlen = max(maxlen, len[tot] = strlen(s[tot] + 1));
  --tot;
  for (int i = (1); i <= (maxlen + 2); i += (1)) putchar('*');
  putchar('\n');
  int t = 0;
  for (int k = (1); k <= (tot); k += (1)) {
    putchar('*');
    int a = (maxlen - len[k]) / 2, b = maxlen - len[k] - a;
    if (t != 0) {
      if (t & 1) swap(a, b);
      t++;
    }
    for (int i = (1); i <= (a); i += (1)) putchar(' ');
    printf("%s", s[k] + 1);
    for (int i = (1); i <= (b); i += (1)) putchar(' ');
    puts("*");
  }
  for (int i = (1); i <= (maxlen + 2); i += (1)) putchar('*');
  putchar('\n');
  return 0;
}
