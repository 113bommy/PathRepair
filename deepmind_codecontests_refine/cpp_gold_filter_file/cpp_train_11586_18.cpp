#include <bits/stdc++.h>
using namespace std;
inline void setIO(string a) {}
int n, m, k, danG, danR, a[10005];
char s[10005];
inline void In(int x) {
  if (x < 0) return;
  for (int i = (0); i <= (9); i++) a[i] += (x >> i) & 1;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (1); i <= (n); i++) {
    scanf("%s", s + 1);
    int ng = 0, nr = 0, fr = 0, se = 0;
    for (int i = (1); i <= (m); i++) {
      if (s[i] == 'G') ng = 1;
      if (s[i] == 'R') nr = 1;
      if (s[i] != '-') {
        if (!fr)
          fr = i;
        else
          se = i;
      }
    }
    if (!se && (m > 1))
      danG |= ng, danR |= nr;
    else if (se && (m > 2) && ((!ng) || (!nr)))
      danG |= ng, danR |= nr;
    else
      In(se - fr - 1);
  }
  if (danG && danR)
    puts("Draw");
  else if (danG)
    puts("First");
  else if (danR)
    puts("Second");
  else {
    for (int i = (0); i <= (9); i++)
      if (a[i] % (k + 1)) {
        printf("First\n");
        return 0;
      }
    printf("Second\n");
  }
  scanf("\n");
  return 0;
}
