#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int a[MAXN];
map<double, int> mp;
int main() {
  int n, ans = 0, abi = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    if (a[i] == 0 && x == 0)
      ++abi;
    else if (a[i] != 0)
      ans = max(ans, ++mp[-1.0 * x / a[i]]);
  }
  ans += abi;
  printf("%d\n", ans);
  return 0;
}
