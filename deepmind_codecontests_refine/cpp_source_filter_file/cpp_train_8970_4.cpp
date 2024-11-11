#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  map<int, vector<int>> kit;
  for (int i = 0; i < n; i++) {
    kit[a[i]].push_back(0);
    for (int j = 1; a[i] > 0; j++) {
      a[i] /= 2;
      kit[a[i]].push_back(j);
    }
  }
  int ans = (int)1e8;
  for (auto [_, it] : kit) {
    if (it.size() >= k) {
      int sum = accumulate(it.begin(), it.begin() + k, 0);
      ans = min(ans, sum);
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
