#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int f = 1, sum = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = (sum << 3) + (sum << 1) + ch - '0';
    ch = getchar();
  }
  return f * sum;
}
const int N = 5010;
int f[N];
char s[N];
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1), del = log(n) + 1, lst = n - (1 << del) + 1;
  memset(f, 1, sizeof(f));
  for (int i = 1; i <= lst; i++) {
    char mx = 'z' + 1;
    for (int p = 0; p < 1 << del; p++)
      if (f[p])
        for (int j = 0; j < del; j++) f[p | (1 << j)] = 1;
    for (int p = 0; p < 1 << del; p++)
      if (i + p <= n && f[p]) mx = min(mx, s[i + p]);
    putchar(mx);
    for (int p = 0; p < 1 << del; p++)
      if (s[i + p] != mx) f[p] = 0;
  }
  puts("");
  return 0;
}
