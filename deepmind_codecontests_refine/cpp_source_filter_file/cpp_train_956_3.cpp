#include <bits/stdc++.h>
using namespace std;
int read() {
  int s = 0, w = 1;
  char ch;
  ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      w = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
int a[1001], s;
int main() {
  int n = read(), m = read(), d = read();
  for (int i = 1; i <= m; i++) {
    a[i] = read();
    s += a[i];
    if (s > n) {
      puts("NO");
      return 0;
    }
  }
  if (s + (m + 1) * (d - 1) < n) {
    puts("NO");
    return 0;
  }
  puts("YES");
  if (d == 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= a[i]; j++) {
        printf("i");
      }
    }
    return 0;
  }
  if (d >= n - s) {
    for (int i = 1; i <= n - s; i++) printf("0 ");
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= a[i]; j++) {
        printf("%d ", i);
      }
    }
    return 0;
  }
  int t = 1;
  while (1) {
    if (d <= n - s) {
      for (int i = 1; i < d; i++) {
        printf("0 ");
      }
      for (int i = 1; i <= a[t]; i++) {
        printf("%d ", t);
      }
      n -= (d + a[t] - 1);
      s -= a[t];
      t++;
    } else {
      for (int i = 1; i <= n - s; i++) printf("0 ");
      for (int i = t; i <= m; i++) {
        for (int j = 1; j <= a[i]; j++) {
          printf("%d ", i);
        }
      }
      break;
    }
  }
  return 0;
}
