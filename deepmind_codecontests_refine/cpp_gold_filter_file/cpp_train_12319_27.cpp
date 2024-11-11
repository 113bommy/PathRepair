#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
int n, a[1000005], f[((1 << 22) - 1) + 5];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    f[a[i] ^ (((1 << 22) - 1))] = a[i];
  }
  for (int i = ((1 << 22) - 1); i >= 0; i--)
    if (f[i] > 0) {
      for (int j = 1; j <= 22; j++)
        if (i >> (j - 1) & 1) {
          int tmp = (1 << (j - 1));
          f[i - tmp] = f[i];
        }
    }
  for (int i = 1; i <= n; i++)
    if (f[a[i]])
      printf("%d ", f[a[i]]);
    else
      printf("-1 ");
  return 0;
}
