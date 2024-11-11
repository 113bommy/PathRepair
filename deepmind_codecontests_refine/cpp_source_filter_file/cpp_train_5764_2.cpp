#include <bits/stdc++.h>
long long n, md;
void rid(int n, int m) {
  int i;
  long long sol = 1, p = 1;
  for (i = 0, p = n; i <= 31; i++) {
    if ((m & (1 << i)) == (1 << i)) {
      sol = (long long)sol * p;
      sol = (long long)sol % md;
    }
    p = (long long)p * p;
    p = (long long)p % md;
  }
  if (sol == 0)
    sol = m - 1;
  else
    sol--;
  printf("%I64d", sol);
}
int main() {
  scanf("%I64d%I64d", &n, &md);
  rid(3, n);
}
