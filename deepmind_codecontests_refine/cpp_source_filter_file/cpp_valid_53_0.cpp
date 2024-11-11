#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = (0); i < (n); i++) cin >> arr[i];
  int z = 0;
  set<int> s;
  for (int i = (0); i < (n); i++) {
    s.insert(arr[i]);
  }
  for (int i = (0); i < (n - 1); i++) {
    if (arr[i + 1] < arr[i]) {
      z++;
      continue;
    }
    auto f = s.find(arr[i]);
    f++;
    if (*f != arr[i + 1]) {
      z++;
      continue;
    }
  }
  if (z > k) {
    cout << "No" << '\n';
    return 0;
  }
  cout << "Yes" << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
