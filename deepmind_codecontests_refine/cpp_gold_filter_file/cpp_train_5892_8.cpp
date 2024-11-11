#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> odd;
  long long ans = 0;
  int min_odd = -100000;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > 0) {
      if (x % 2 == 0)
        ans += (long long)x;
      else
        odd.push_back(x);
    } else if (x % 2 != 0) {
      min_odd = max(min_odd, x);
    }
  }
  if (odd.empty()) {
    ans += (long long)min_odd;
  } else {
    sort(odd.rbegin(), odd.rend());
    for (int x : odd) ans += (long long)x;
    if (ans % 2 == 0) {
      ans = max(ans - (long long)odd.back(), ans + (long long)min_odd);
    }
  }
  cout << ans << '\n';
  return 0;
}
