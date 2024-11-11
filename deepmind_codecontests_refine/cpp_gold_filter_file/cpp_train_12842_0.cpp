#include <bits/stdc++.h>
int a, b, k;
bool z[1100000];
int cnt[1100000], i;
bool ok(int len) {
  for (i = a; i <= b - len + 1; ++i)
    if (cnt[i + len - 1] - cnt[i - 1] < k) return false;
  return true;
}
int main() {
  scanf("%d %d %d", &a, &b, &k);
  for (i = 1; i <= 1000000; i++) z[i] = true;
  z[1] = false;
  for (i = 2; i <= 1000; i++)
    if (z[i])
      for (int j = i + i; j <= 1000000; j += i) z[j] = false;
  cnt[0] = 0;
  for (i = 1; i <= 1000000; i++) cnt[i] = cnt[i - 1] + z[i];
  int st = 1, dr = b - a + 1, last = -1;
  while (st <= dr) {
    int med = (st + dr) / 2;
    if (ok(med)) {
      last = med;
      dr = med - 1;
    } else
      st = med + 1;
  }
  if (ok(last))
    printf("%d", last);
  else
    printf("-1");
  return 0;
}
