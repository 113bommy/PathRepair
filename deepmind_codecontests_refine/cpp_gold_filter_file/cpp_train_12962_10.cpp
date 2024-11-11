#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
int n;
char a[1000010], b[1000010];
int fail[1000010];
int main() {
  n = read();
  scanf("%s", b + 1);
  scanf("%s", a + 1);
  n--;
  for (int i = (1); i <= (n); i++)
    if (a[i] == 'N')
      a[i] = 'S';
    else if (a[i] == 'S')
      a[i] = 'N';
    else if (a[i] == 'E')
      a[i] = 'W';
    else if (a[i] == 'W')
      a[i] = 'E';
  reverse(a + 1, a + n + 1);
  int j = 0;
  for (int i = (2); i <= (n); i++) {
    for (; j && a[j + 1] != a[i]; j = fail[j])
      ;
    fail[i] = (a[j + 1] == a[i]) ? ++j : j;
  }
  j = 0;
  for (int i = (1); i <= (n); i++) {
    for (; j && a[j + 1] != b[i]; j = fail[j])
      ;
    if (a[j + 1] == b[i]) j++;
  }
  if (j)
    printf("NO\n");
  else
    printf("YES\n");
}
