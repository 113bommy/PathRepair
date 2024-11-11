#include <bits/stdc++.h>
template <typename T>
T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T gcd(T x, T y) {
  return x ? gcd(y % x, x) : y;
}
int main() {
  int n;
  char a[150];
  while (~scanf("%d %s", &n, a)) {
    int t = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '0') {
        if (t) t++;
        break;
      }
      t++;
    }
    printf("%d\n", t);
  }
}
