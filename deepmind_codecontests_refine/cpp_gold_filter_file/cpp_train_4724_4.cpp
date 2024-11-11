#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> ans(n);
  int l = 0, r = n - 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'r') {
      ans[l] = i + 1;
      l++;
    } else {
      ans[r] = i + 1;
      r--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
