#include <bits/stdc++.h>
using namespace std;
;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  std::vector<int> v(n);
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  while (!v[(n - 1) / 2] == k) {
    v.push_back(k);
    ++n;
    ++ans;
    sort(v.begin(), v.end());
  }
  cout << ans;
}
