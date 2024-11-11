#include <bits/stdc++.h>
using namespace std;
long long n, x, t[500005], s, cur;
long long ans[50005];
int main() {
  cin >> n;
  for (int i = 0; i < n / 2; i++) cin >> t[i];
  ans[0] = 0;
  ans[n - 1] = t[0];
  for (int i = 1; i < n / 2; i++) {
    cur = t[i] - ans[i - 1];
    if (cur > ans[n - i]) cur = ans[n - i];
    ans[n - i - 1] = cur;
    ans[i] = t[i] - cur;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
