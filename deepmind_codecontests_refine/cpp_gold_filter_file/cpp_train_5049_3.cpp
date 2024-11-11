#include <bits/stdc++.h>
using namespace std;
long long i, n, k, x, ans, id, mx, mul;
long long arr[200002];
long long prefix[200002];
long long suffix[200002];
int main() {
  cin >> n >> k >> x;
  mul = 1;
  ans = 0;
  mx = 0;
  for (i = 1; i <= k; i++) {
    mul *= x;
  }
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] | arr[i];
  }
  for (i = n; i >= 1; i--) {
    suffix[i] = suffix[i + 1] | arr[i];
  }
  for (i = 1; i <= n; i++) {
    ans = max(ans, prefix[i - 1] | (arr[i] * mul) | suffix[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
