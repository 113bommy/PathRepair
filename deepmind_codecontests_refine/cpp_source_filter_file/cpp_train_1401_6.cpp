#include <bits/stdc++.h>
using namespace std;
const int maxn = 20100;
int ans[maxn];
bool check(int x) {
  int q = sqrt(x);
  for (int i = 2; i <= q; ++i) {
    if (x % i == 0) return 0;
  }
  return 1;
}
int main() {
  int n;
  scanf("%d", &n);
  int m = (n + 1) * n / 2;
  for (int i = 1; i <= n; ++i) ans[i] = 1;
  if (check(m)) {
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    puts("");
    return 0;
  }
  if (m & 1 && check(m - 2)) ans[3] = 3, m -= 3;
  for (int i = 2; i <= n; ++i) {
    if (check(i) && (check(m - i))) {
      ans[i] = 2;
      break;
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
