#include <bits/stdc++.h>
int val[10] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};
int a, b;
long long ans;
char s[10];
void work() {
  for (int i = 0; s[i]; ++i) ans = ans + val[s[i] - '0'];
}
int main() {
  scanf("%d%d", &a, &b);
  for (int i = a; i <= b; ++i) {
    sprintf(s, "%d\0", i);
    work();
  }
  printf("%I64d\n", ans);
  return 0;
}
