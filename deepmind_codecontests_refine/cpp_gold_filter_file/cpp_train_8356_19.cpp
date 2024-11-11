#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int t, n;
int main() {
  int i, j, k, l, r;
  t = read();
  while (t--) {
    n = read();
    bool flag = 0;
    for (i = 0; i * 7 <= n; i++) {
      for (j = 0; j * 5 + i * 7 <= n; j++) {
        k = n - i * 7 - j * 5;
        if (k % 3 == 0) {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag)
      puts("-1");
    else
      printf("%d %d %d\n", k / 3, j, i);
  }
  return 0;
}
