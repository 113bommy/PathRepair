#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    v.push_back(k);
  }
  sort(v.begin(), v.end());
  int ans = (int)1e9;
  if (n == 2) {
    cout << v[1] - v[0];
    return 0;
  }
  for (int i = 0; i < n / 2 - 1; i++) {
    ans = min(ans, v[i + n / 2] + v[i]);
  }
  cout << ans;
}
