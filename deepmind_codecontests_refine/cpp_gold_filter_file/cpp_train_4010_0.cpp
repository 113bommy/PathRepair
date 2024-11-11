#include <bits/stdc++.h>
int state_odd(int x) {
  if (x == 0 || x == 2) return 0;
  if (x == 1 || x == 3) return 1;
  if (x == 4) return 2;
  if (x & 1) return 0;
  int l = state_odd(x / 2);
  if (l == 1)
    return 2;
  else
    return 1;
}
int state_even(int x) {
  if (x <= 2)
    return x;
  else
    return (x & 1 ? 0 : 1);
}
int main() {
  int ret = 0, a, n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (k & 1)
      ret ^= state_odd(a);
    else
      ret ^= state_even(a);
  }
  puts(ret ? "Kevin" : "Nicky");
  return 0;
}
