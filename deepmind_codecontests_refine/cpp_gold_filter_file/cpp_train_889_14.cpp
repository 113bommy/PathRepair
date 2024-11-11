#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 9;
int n, m, a[maxn], u, v, res;
int main() {
  while (~scanf("%d %d", &(n), &(m))) {
    res = 0;
    for (int i = (1); i <= (n); i++) scanf("%d", &(a[i]));
    for (int i = (1); i <= (m); i++) {
      scanf("%d %d", &(u), &(v));
      int ans = 0;
      for (int j = (u); j <= (v); j++) {
        ans += a[j];
      }
      res += ans > 0 ? ans : 0;
    }
    printf("%d\n", res);
  }
  return 0;
}
