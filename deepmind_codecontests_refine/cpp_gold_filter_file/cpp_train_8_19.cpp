#include <bits/stdc++.h>
int n, cnt, len;
char c[10001];
int main() {
  scanf("%d", &n);
  while ((c[0] = getchar()) < 32 || c[0] > 126)
    ;
  while ((c[++len] = getchar()) >= 32 && c[len] <= 126)
    ;
  for (int i = 0; i <= n; i++)
    if (c[i] == '8') cnt++;
  printf("%d", (n / 11 < cnt ? n / 11 : cnt));
}
