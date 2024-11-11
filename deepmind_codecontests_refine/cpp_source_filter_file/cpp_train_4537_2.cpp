#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  k = min(k, n - k);
  int idx = 1, ans = 1, cnt = 1;
  for (int i = 0; i < n; i++) {
    ans += cnt;
    idx = (idx + k) % n;
    if (idx > 1 && idx <= k) {
      ans++;
      cnt += 2;
    }
    cout << ans << " ";
  }
  return 0;
}
