#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int mod = 998244353;
const int maxn = 1e6 + 10;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int l = 1, r = m; l < r; ++l, --r) {
    for (int i = 1; i <= n; ++i) {
      printf("%d %d\n%d %d\n", i, l, (n - i + 1), r);
    }
  }
  if (m % 2 == 1) {
    for (int i = 1; i <= n / 2; ++i) {
      printf("%d %d\n%d %d\n", i, m / 2 + 1, n - i + 1, m / 2 + 1);
    }
    if (n % 2 == 1) {
      printf("%d %d\n", n / 2 + 1, m / 2 + 1);
    }
  }
}
