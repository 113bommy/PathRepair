#include <bits/stdc++.h>
using namespace std;
int n;
char a[200003], ans[400003];
int main() {
  scanf("%d%s", &n, a);
  srand(time(NULL));
  int res = 0, ai = 0, tm = 0;
  for (int i = 0; i < n; i++) {
    if (i && (rand() % 3)) {
      ans[ai++] = '+';
      res += tm;
      tm = 0;
    }
    ans[ai++] = a[i];
    tm = 10 * tm + (a[i] & 15);
  }
  res += tm;
  puts(ans);
  sprintf(a, "%d", res);
  n = (int)strlen(a);
  for (int bit = 0; bit < 1 << (n - 1); bit++) {
    int cnt = 0, idx = 0, tmp = 0;
    res = 0;
    for (int i = 0; i < n; i++) {
      if (i) {
        if (bit >> (i - 1) & 1) {
          ans[idx++] = '+';
          res += tmp;
          tmp = 0;
        }
      }
      ans[idx++] = a[i];
      tmp = tmp * 10 + (a[i] & 15);
    }
    ans[idx] = 0;
    res += tmp;
    int dig = 0;
    tmp = res;
    while (tmp) {
      dig += tmp % 10;
      tmp /= 10;
    }
    if (dig < 10) {
      puts(ans);
      idx = 0;
      sprintf(a, "%d", res);
      n = (int)strlen(a);
      for (int i = 0; i < n; i++) {
        if (i) ans[idx++] = '+';
        ans[idx++] = a[i];
      }
      ans[idx] = 0;
      puts(ans);
      return 0;
    }
  }
  assert(0);
  return 0;
}
