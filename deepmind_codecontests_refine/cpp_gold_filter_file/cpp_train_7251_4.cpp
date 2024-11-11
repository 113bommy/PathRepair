#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, k, x, y;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(x * 60 + y);
  }
  sort(v.begin(), v.end());
  int ans;
  if (v[0] >= k + 1) {
    ans = 0;
    cout << ans / 60 << " " << ans % 60 << "\n";
    return 0;
  }
  ans = -1;
  for (int i = 1; i < n; i++) {
    if (v[i] - v[i - 1] >= k + k + 2) {
      ans = v[i - 1] + k + 1;
      break;
    }
  }
  if (ans == -1) ans = v[n - 1] + k + 1;
  cout << ans / 60 << " " << ans % 60 << "\n";
  return 0;
}
