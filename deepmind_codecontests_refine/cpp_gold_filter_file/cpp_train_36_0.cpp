#include <bits/stdc++.h>
int main() {
  int n, A = 0, I = 0, F = 0, ans = 0;
  char c[200001];
  scanf("%d", &n);
  scanf("%s", c);
  for (int i = 0; i < n; i++) {
    if (c[i] == 'A')
      A++;
    else if (c[i] == 'I')
      I++;
    else if (c[i] == 'F')
      F++;
  }
  if (I == 0)
    ans = A;
  else if (I == 1)
    ans = 1;
  printf("%d\n", ans);
  return 0;
}
