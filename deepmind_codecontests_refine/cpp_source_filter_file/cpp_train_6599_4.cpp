#include <bits/stdc++.h>
using namespace std;
int s[100001];
char x[100001];
unsigned int f[100001];
int main() {
  int n;
  scanf("%d", &n);
  int i, j;
  scanf("%s", x);
  for (i = n; i >= 1; i--) s[i] = s[i + 1] + (x[i - 1] == '?');
  if (s[1] % 2 == 1) {
    printf("0\n");
    return 0;
  }
  f[0] = 1;
  int xt = n / 2;
  for (i = 1; i <= n; i++) {
    if (x[i - 1] == '?') {
      for (j = i / 2; xt - j <= s[i + 1] && j > 0; j -= 2) {
        f[j] += f[j - 1];
        f[j - 1] += f[j - 2];
      }
    }
  }
  unsigned int ans = f[xt];
  for (i = 1; i <= s[1] - xt; i++) ans = ans * 25;
  printf("%u\n", ans);
  return 0;
}
