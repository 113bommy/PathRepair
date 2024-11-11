#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<long long> v;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    v.push_back(num);
  }
  int mx = 0;
  vector<int> ans;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i] >= mx) {
      ans.push_back(0);
      mx = v[i];
    } else {
      ans.push_back(mx - v[i] + 1);
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
