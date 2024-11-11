#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int main() {
  int n, m, sum, a, c[2 * maxn];
  long long res = 0;
  memset(c, 0, sizeof(c));
  scanf("%d%d", &n, &m);
  sum = n;
  c[n] = 1;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a < m) {
      sum--;
    } else if (a > m) {
      sum++;
    }
    if (a == m) flag = true;
    if (!flag)
      c[sum]++;
    else
      res += c[sum] + c[sum - 1];
  }
  printf("%64d\n", res);
  return 0;
}
