#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, angka1 = 0, angka2 = 0, angka3 = 0, angka4 = 0, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &s);
    if (n == 1)
      angka1++;
    else if (s == 2)
      angka2++;
    else if (s == 3)
      angka3++;
    else if (s == 4)
      angka4++;
  }
  ans += angka4;
  ans += angka3;
  angka1 -= min(angka1, angka3);
  ans += angka2 / 2;
  angka2 %= 2;
  if (angka2 == 1) {
    ans += 1;
    angka2 = 0;
    angka1 -= min(angka1, 2);
  }
  ans += angka1 / 4;
  angka1 %= 4;
  if (angka1 > 0) ans++;
  printf("%d\n", ans);
  return 0;
}
