#include <bits/stdc++.h>
int b[10];
int a[1000000];
bool ss1(int x) {
  if (x == 2) return 1;
  if (x < 2 || x % 2 == 0) return 0;
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0) return 0;
  return 1;
}
bool ss(int n) {
  int k = 0, m = n, s = 0;
  while (m) {
    b[k] = m % 10;
    m /= 10;
    k++;
  }
  for (int i = 0; i < k; i++) {
    s = s * 10 + b[i];
  }
  if (ss1(s) && ss1(n) && s != n)
    return 1;
  else
    return 0;
}
int main() {
  for (int i = 13, k = 0; i <= 11184; i++) {
    if (ss(i)) a[k] = i, k++;
  }
  int n;
  scanf("%d", &n);
  printf("%d", a[n - 1]);
  return 0;
}
