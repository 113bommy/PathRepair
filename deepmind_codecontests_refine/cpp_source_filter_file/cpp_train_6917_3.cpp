#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n, m, last, x[1005], y[1005];
int calc(int p) {
  int ans = 0;
  for (int i = 0; i < m; i++) ans += (x[i] >= p && p <= y[i]);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  last = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = 1; i <= 100; i++) {
    if (calc(i) != 1) {
      printf("%d %d\n", i, calc(i));
      return 0;
    }
  }
  puts("OK");
  return 0;
}
