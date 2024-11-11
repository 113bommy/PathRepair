#include <bits/stdc++.h>
using namespace std;
int p[5], a, b;
int read() {
  int k = 0, flag = 1;
  char b = getchar();
  while (b < '0' || b > '9') {
    if (b == '-') flag = -1;
    b = getchar();
  }
  while (b >= '0' && b <= '9') {
    k = (k << 3) + (k << 1) + b - '0';
    b = getchar();
  }
  return k * flag;
}
int main() {
  int ans = 0;
  for (int i = 1; i <= 4; i++) {
    p[i] = read();
  }
  a = read(), b = read();
  for (int i = a; i <= b; i++) {
    if (i % p[1] == 0 && i % p[2] == 0 && i % p[3] == 0 && i % p[4] == 0) ans++;
  }
  printf("%d", ans);
}
