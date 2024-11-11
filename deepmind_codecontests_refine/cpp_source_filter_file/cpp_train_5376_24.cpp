#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int quick(int n, int m) {
  int ans = 1, base = n;
  while (m > 0) {
    if (m & 1) ans = ans * base % mod;
    base = base * base % mod;
    m >>= 1;
  }
  return ans;
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n >= 20) {
      printf("%d\n", m);
      continue;
    }
    printf("%d\n", m % quick(2, n));
  }
  return 0;
}
