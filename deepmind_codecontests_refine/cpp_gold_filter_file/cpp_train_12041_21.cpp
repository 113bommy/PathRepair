#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 5) {
    puts("-1");
  }
  if (n >= 6) {
    for (int i = 2; i <= n - 2; i++) {
      printf("%d %d\n", 1, i);
    }
    printf("%d %d\n", 2, n - 1);
    printf("%d %d\n", 2, n);
  }
  printf("%d %d\n", 1, 2);
  for (int i = 3; i <= n; i++) {
    printf("%d %d\n", 2, i);
  }
}
