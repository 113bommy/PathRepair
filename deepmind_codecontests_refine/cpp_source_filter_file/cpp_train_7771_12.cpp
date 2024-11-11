#include <bits/stdc++.h>
int ara[1001];
int main() {
  int a, b, t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d%d", &a, &b);
    ara[a]++;
    ara[b]++;
  }
  int c = 0;
  for (int i = 1; i <= t; i++) {
    if (ara[i] == 1) c++;
  }
  printf("%d\n", c);
  return 0;
}
