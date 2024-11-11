#include <bits/stdc++.h>
int n, i, a;
long p = 0, t[21] = {0};
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    t[a + 10]++;
  }
  for (i = 0; i < 10; i++) p += t[i] * t[20 - i];
  p += t[10] * (t[10] - 1) / 2;
  printf("%I64d", p);
}
