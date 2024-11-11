#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long pre[1000005];
long long post[1000005];
long long ans;
int main() {
  long long n, k, x;
  cin >> n >> k >> x;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long mul = 1;
  while (k--) mul *= x;
  for (long long i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] | a[i];
  }
  for (long long i = n; i >= 1; i--) {
    post[i] = post[i + 1] | a[i];
  }
  for (long long i = 1; i <= n; i++) {
    ans = max(ans, pre[i - 1] | a[i] * mul | post[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
