#include <bits/stdc++.h>
using namespace std;
int abso(int a) {
  if (a < 0) return -a;
  return a;
}
int mini(int a, int b) {
  if (a < b) return a;
  return b;
}
int maxi(int a, int b) {
  if (a > b) return a;
  return b;
}
long long int n, a[1000] = {0}, b[1000] = {0}, x, y, s = 0, c[2000] = {0},
                 d[1000] = {0};
int main() {
  scanf("%I64d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d", &x, &y);
    x--;
    y--;
    if (x > y)
      a[x - y]++;
    else
      b[y - x]++;
    c[x + y]++;
  }
  for (int i = 0; i < 1000; i++) {
    s += a[i] * (a[i] - 1) / 2;
    s += b[i] * (b[i] - 1) / 2;
    s += c[i] * (c[i] - 1) / 2;
  }
  printf("%I64d", s);
  return 0;
}
