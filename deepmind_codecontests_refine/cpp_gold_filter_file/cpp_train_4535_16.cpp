#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 9;
const int inf = 2e9 + 9;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
long long a[maxn];
long long pre[maxn];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    long long ans = -1;
    pre[1] = 0;
    for (int i = 2; i <= n; i++) pre[i] = pre[i - 1] + a[i] - a[1];
    ans = pre[n];
    long long now = a[1];
    for (int i = 2; i <= n; i++) {
      long long t1 = pre[i - 1];
      t1 = 1LL * (i - 1) * (a[i] - a[1]) - t1;
      long long t2 = pre[n] - pre[i];
      t2 = t2 - 1LL * (n - i) * (a[i] - a[1]);
      if (t1 + t2 < ans) {
        ans = t1 + t2;
        now = a[i];
      }
    }
    printf("%lld\n", now);
  }
  return 0;
}
