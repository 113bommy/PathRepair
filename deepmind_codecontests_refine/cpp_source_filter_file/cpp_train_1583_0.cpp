#include <bits/stdc++.h>
using namespace std;
char c;
char s[10000];
int notp[10000], p[10000], f[10000];
int h[10000], res[10000];
int tot;
int main() {
  scanf("%c", &c);
  int len = 0;
  for (; c != '\n'; scanf("%c", &c)) s[++len] = c;
  if (len <= 3) {
    printf("YES\n");
    for (int i = 1; i <= len; i++) printf("%c", s[i]);
    printf("\n");
    return 0;
  }
  for (int i = 2; i <= len; i++) {
    if (!notp[i]) p[++tot] = i;
    for (int j = 1; (j <= tot && i * p[j] <= len); j++) {
      notp[i * p[j]] = 1;
      if (!(i % p[j])) break;
    }
  }
  for (int i = 1; i <= len; i++) f[i] = i;
  int total = 1;
  for (int i = 1; i <= tot; i++)
    if ((len / p[i]) >= 2)
      for (int j = 1; p[i] * j <= len; j++)
        if (f[p[i] * j] != 2) f[p[i] * j] = 2, total++;
  for (int i = 1; i <= len; i++) h[s[i] - 'a' + 1]++;
  int check = 0;
  int ans = 0;
  for (int i = 1; i <= 26; i++)
    if (h[i] >= total) {
      check = 1;
      ans = i;
      break;
    }
  if (!check) {
    printf("NO\n");
    return 0;
  }
  h[ans] -= tot;
  for (int i = 1; i <= len; i++) {
    if (f[i] == 2)
      res[i] = ans;
    else
      for (int j = 1; j <= 26; j++)
        if (h[j] > 0) {
          h[j]--, res[i] = j;
          break;
        }
  }
  printf("YES\n");
  for (int i = 1; i <= len; i++) printf("%c", res[i] - 1 + 'a');
  printf("\n");
}
