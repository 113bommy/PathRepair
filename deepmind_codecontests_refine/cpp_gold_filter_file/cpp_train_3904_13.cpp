#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dis(int x, int y) {
  int res = min(x - 1, y - 1);
  res = min(res, n - x);
  res = min(res, m - y);
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int mn = 1e5;
  for (int i = 0, x, y; i < k; ++i) {
    scanf("%d%d", &x, &y);
    mn = min(mn, dis(x, y));
  }
  if (mn > 4) {
    puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}
