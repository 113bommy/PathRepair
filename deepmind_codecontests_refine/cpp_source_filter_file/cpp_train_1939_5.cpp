#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int n, ans = 2e9;
int a[110], b[110];
int main() {
  n = read();
  for (int i = 1; i <= n * 2; i++) {
    a[i] = read();
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = i + 1; j <= 2 * n; j++) {
      int cnt = 0, flag = 0, last;
      for (int k = 1; k <= 2 * n; k++) {
        if (k == i || k == j) continue;
        if (!flag) {
          last = a[k];
          flag = 1;
        } else {
          cnt += a[k] - last;
          flag = 0;
        }
      }
      ans = min(ans, cnt);
    }
  }
  printf("%d\n", ans);
  return 0;
}
