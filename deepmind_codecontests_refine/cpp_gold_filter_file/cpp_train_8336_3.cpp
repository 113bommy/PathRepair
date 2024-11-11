#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  vector<long long> pows;
  long long m = 1;
  while (m <= 100000000000) pows.push_back(m), m *= 2;
  ;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << 1;
    return 0;
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (auto j : pows) {
      auto left = binary_search(a.begin(), a.begin() + i, j - a[i]);
      auto right = binary_search(a.begin() + i + 1, a.end(), j - a[i]);
      if (!left && !right) cnt++;
    }
    if (cnt == pows.size()) ans++;
  }
  cout << ans;
  return 0;
}
