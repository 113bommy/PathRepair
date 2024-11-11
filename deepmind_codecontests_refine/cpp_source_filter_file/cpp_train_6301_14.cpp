#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
char s[N];
int n, k, sum[N];
int res = 0xfffffff;
bool check(int x) {
  int l, r;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      l = max(i - x, 1);
      r = min(i + x, n);
      if (sum[r] - sum[l - 1] - 1 >= k) return true;
    }
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0')
      sum[i] = sum[i - 1] + 1;
    else
      sum[i] = sum[i - 1];
  }
  int r = n, l = 0, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
