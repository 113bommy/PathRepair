#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int res = 0, c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  do {
    res = (res << 3) + (res << 1) + (c ^ 48);
  } while (c = getchar(), c >= '0' && c <= '9');
  return res;
}
int a[10010], b[10010], good[10010];
int main() {
  int N = read(), M, ans = 0;
  for (int i = 1; i <= N; i++) {
    good[i] = getchar() == '1';
  }
  for (int i = 1; i <= N; i++) {
    a[i] = read(), b[i] = read();
  }
  for (int i = 0; i <= 100; i++) {
    int now = 0;
    for (int j = 1; j <= N; j++) {
      if (i < b[j]) {
        now += good[j];
      } else
        now += good[j] ^ (((i - b[j]) / a[j]) % 2);
    }
    if (now > ans) ans = now;
  }
  printf("%d\n", ans);
  return 0;
}
