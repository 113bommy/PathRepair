#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
char a[maxn];
int b[maxn][4];
int main() {
  scanf("%s", a);
  int len = strlen(a);
  for (int i = 0; i < len; i++) {
    if (a[i] == 'o')
      b[i][0] = 0;
    else
      b[i][0] = 1;
  }
  int lw = 0, rw = 0;
  for (int i = 1; i < len; i++) {
    if (b[i - 1][0] == 1 && b[i][0] == 1) lw++;
    if (b[i][0] == 0) b[i][1] = lw;
  }
  for (int i = len - 2; i >= 0; i--) {
    if (b[i + 1][0] == 1 && b[i][0] == 1) rw++;
    if (b[i][0] == 0) b[i][2] = rw;
  }
  long long res = 0;
  for (int i = 0; i < len; i++) {
    if (b[i][0] == 0) res += b[i][1] * b[i][2];
  }
  printf("%lld\n", res);
}
