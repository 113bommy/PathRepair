#include <bits/stdc++.h>
using namespace std;
char s[1111111];
int main() {
  int i;
  scanf("%s", s);
  int t = strlen(s);
  int sum1 = 0, sum0 = 0;
  int ans = 0;
  i = 0;
  int f1 = 0;
  int cont = 0;
  while (i < t) {
    sum1 = 0;
    sum0 = 0;
    while (s[i] == '1') i++, sum1++;
    while (s[i] == '0') i++, sum0++;
    if (sum1 == 1 && !cont) {
      ans += 1;
      continue;
    }
    if (sum0 == 1) {
      cont++;
      continue;
    }
    ans += 2 + cont;
    cont = 0;
  }
  printf("%d\n", ans);
}
