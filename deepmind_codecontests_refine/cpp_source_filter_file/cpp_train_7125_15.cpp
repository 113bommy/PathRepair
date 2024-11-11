#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 2e5 + 10, M = 1e6 + 10, inf = 2147483647;
const long long INF = 1e18 + 10, mod = 2147493647;
int a[N];
int l[N], r[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i - 1])
      l[i] = l[i - 1] + 1;
    else
      l[i] = 1;
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] < a[i + 1])
      r[i] = r[i + 1] + 1;
    else
      r[i] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      ans = max(ans, r[i + 1] + 1);
    else if (i == n)
      ans = max(l[i - 1] + 1, ans);
    else if (a[i + 1] == a[i - 1])
      ans = max(ans, max(l[i - 1], r[i + 1]) + 1);
    else
      ans = max(ans, l[i - 1] + r[i + 1] + 1);
  }
  printf("%d\n", ans);
  return 0;
}
