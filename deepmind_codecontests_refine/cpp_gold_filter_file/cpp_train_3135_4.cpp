#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  scanf("%lld%lld", &m, &n);
  if (m < n) {
    swap(n, m);
  }
  long long ans = 0;
  if (1 == n) {
    ans = m / 6 * 6 + max(m % 6 - 3, (long long)0) * 2;
  } else if (2 == n) {
    if (2 == m) {
      ans = 0;
    } else if (3 == m) {
      ans = 4;
    } else if (7 == m) {
      ans = 12;
    } else {
      ans = m * 2;
    }
  } else {
    ans = n * m;
    if (ans & 1) {
      --ans;
    }
  }
  printf("%lld", ans);
  return 0;
}
