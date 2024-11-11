#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
int a[100010];
int b[40];
int add(int x) {
  for (int i = 30; i >= 0; i--) {
    if ((x & (1 << i))) {
      if (!b[i]) {
        b[i] = x;
        return 1;
      } else
        x ^= b[i];
    }
  }
  return 0;
}
int res;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];
  if (a[n] == 0) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) res += add(a[i]);
  printf("%d\n", res);
  return 0;
}
