#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int k, n[3], t[3];
  cin >> k;
  for (int i = 0; i < 3; i++) {
    cin >> n[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> t[i];
  }
  vector<int> ans(k);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < k; j++) {
      ans[j] = max(ans[j], j < n[i] ? 0 : ans[j - n[i]]) + t[i];
    }
  }
  cout << *max_element(begin(ans), end(ans));
  return 0;
}
