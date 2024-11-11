#include <bits/stdc++.h>
bool v[333];
int n, a[3], sg, adder;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i), sg ^= a[i];
  if (n == 2) {
    if (a[1] < a[0]) a[1] ^= a[0], a[0] ^= a[1], a[1] ^= a[0];
    for (int i = 1; i < a[0]; ++i)
      if (!v[i]) v[i++ + adder] = true;
    if (a[0]) sg = !(!v[a[0]] && a[0]++ + adder == a[1]);
  }
  puts(sg ? "BitLGM" : "BitAryo");
  return 0;
}
