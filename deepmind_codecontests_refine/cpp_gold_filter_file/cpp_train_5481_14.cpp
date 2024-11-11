#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n, a[maxn], s1[maxn], s2[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    s1[i] = s1[i - 1] + (a[i] == 1);
    s2[i] = s2[i - 1] + (a[i] == 2);
  }
  int ans = max(s1[n], s2[n]);
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, s1[i] + s2[n] - s2[i]);
    int res = 0;
    for (int j = i; j >= 1; --j) {
      res = max(res, s1[i] - s1[j]) + (a[j] == 2);
      ans = max(ans, s1[j - 1] + res + s2[n] - s2[i]);
    }
  }
  ans = min(ans, n);
  printf("%d\n", ans);
  return 0;
}
