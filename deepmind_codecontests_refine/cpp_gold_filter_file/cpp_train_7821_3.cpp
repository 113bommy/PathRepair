#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int main() {
  long long a[maxn];
  long long n, ans = 0, flag;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  ans = a[n];
  flag = a[n];
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] >= flag)
      flag = flag - 1;
    else
      flag = a[i];
    if (flag <= 0) flag = 0;
    ans += flag;
  }
  printf("%lld\n", ans);
}
