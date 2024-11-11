#include <bits/stdc++.h>
int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  s *= 100;
  int max = 0;
  bool tr = false;
  for (int i = 1; i <= n; i++) {
    int d, c;
    scanf("%d%d", &d, &c);
    int money = d * 100 + c;
    if (money <= s) {
      tr = true;
      int sweet = (s - money) % 100;
      if (max < sweet) max = sweet;
    }
  }
  if (tr == false)
    printf("-1\n");
  else
    printf("%d\n", max);
}
