#include <bits/stdc++.h>
using namespace std;
const int N = 100008;
char a[N], b[N];
int f[30];
int main(void) {
  int n, i, k, sta, la, lb, p;
  sta = 0;
  scanf("%s", a + 1);
  for (i = 1; a[i]; i++) f[a[i] - 'a'] = 1;
  scanf("%s", a + 1);
  la = strlen(a + 1);
  for (i = 1; i <= la; i++)
    if (a[i] == '*') {
      sta = i;
      break;
    }
  scanf("%d", &n);
  while (n--) {
    scanf("%s", b + 1);
    lb = strlen(b + 1);
    if (la > lb) {
      if (la == lb + 1 && sta)
        ;
      else {
        printf("NO\n");
        continue;
      }
    }
    if (sta == 0 && lb != la) {
      printf("NO\n");
      continue;
    }
    p = 1;
    if (sta)
      k = sta;
    else
      k = la + 1;
    for (i = 1; p && i < k; i++)
      if (a[i] == b[i] || (a[i] == '?' && f[b[i] - 'a'] == 1))
        ;
      else {
        p = 0;
        break;
      }
    if (sta)
      k = sta;
    else
      k = 0;
    for (i = la; p && i > k; i--)
      if (a[i] == b[lb - (la - i + 1) + 1] ||
          (a[i] == '?' && f[b[lb - (la - i + 1) + 1] - 'a'] == 1))
        ;
      else {
        p = 0;
        break;
      }
    if (p && sta && la != lb)
      for (i = sta; p && i <= lb - (la - sta + 1) + 1; i++)
        if (f[b[i] - 'a'] == 1) {
          p = 0;
          break;
        }
    if (p)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
