#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long a[N];
long long k[N];
long long c[N];
int n, m;
int check(int L, int R, long long X) {
  int l = L, r = R, ans, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (c[mid] - c[L - 1] > X) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    c[i] = c[i - 1] + a[i];
  }
  for (int i = 1; i <= m; i++) scanf("%lld", &k[i]);
  long long sum = 0;
  for (int i = 1; i <= m; i++) {
    sum += k[i];
    if (c[n] <= sum) {
      sum = 0;
      printf("%d\n", n);
      continue;
    }
    printf("%d\n", n - check(1, n, sum) + 1);
  }
}
