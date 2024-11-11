#include <bits/stdc++.h>
int main() {
  int n, y[27] = {}, i, c = 0;
  char x[100001];
  scanf("%d %s", &n, x);
  for (i = 0; i < n; i++)
    if (!y[x[i] - 97]) {
      y[x[i] - 97]++;
      c++;
    }
  if (n - c < 26)
    printf("%d", n - c);
  else
    printf("-1");
}
