#include <bits/stdc++.h>
long long pow(int a, int b) {
  long long x = 1;
  for (int i = 1; i <= b; i++) x *= a;
  return x;
}
long long n, m, s, t;
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i <= 30; i++)
    for (int j = 0; j <= 25; j++) {
      t = pow(2, i) * pow(3, j);
      if (t > m) break;
      if (t >= n && t <= m) s++;
    }
  printf("%d", s);
}
