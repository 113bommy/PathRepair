#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main() {
  long long i, j, n, ans, p;
  while (scanf("%lld", &n) == 1) {
    ans = 1;
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    long long mini = n - a[n];
    for (i = n; i >= 1; i--) {
      mini = min(mini, i - a[i]);
      if (a[i] == 0) {
        if (mini >= i) ans++;
      }
    }
    cout << min(n, ans) << endl;
  }
  return 0;
}
