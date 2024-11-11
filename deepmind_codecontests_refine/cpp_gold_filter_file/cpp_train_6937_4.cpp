#include <bits/stdc++.h>
int main() {
  int n, pos, l, r;
  scanf("%d%d%d%d", &n, &pos, &l, &r);
  if (l == 1 && r == n) {
    printf("0\n");
  } else if (l == 1) {
    printf("%d", abs(r - pos) + 1);
  } else if (r == n) {
    printf("%d", abs(pos - l) + 1);
  } else
    printf("%d",
           ((abs(pos - l)) > (abs(pos - r)) ? abs(pos - r) : abs(pos - l)) + 2 +
               abs(r - l));
}
