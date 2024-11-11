#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans = 0, b;
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  ans += v[n - 1];
  b = ans;
  for (int i = n - 2; i >= 0; i--) {
    if (!b) break;
    if (v[i] == b) {
      ans += b - 1;
      b--;
    }
    if (v[i] < b) {
      ans += v[i];
      b = v[i];
    }
  }
  cout << ans;
  return 0;
}
