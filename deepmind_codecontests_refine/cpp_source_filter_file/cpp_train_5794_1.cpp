#include <bits/stdc++.h>
using namespace std;
int n, k, a[10001], ans[10001];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ans[i] = -1;
    a[i]--;
  }
  ans[0] = min(n, k + 1);
  for (int i = 1; i < n; ++i) {
    if (a[i] != -1)
      ans[i] =
          ans[a[i]] + min(n - 1, i + k) - max(min(n, a[i] + k + 1), i - k) + 1;
    else
      ans[i] = min(n - 1, i + k) - max(0, i - k) + 1;
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
}
