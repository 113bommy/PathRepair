#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v, v1;
  for (int i = 0; i < n; i++) {
    int t, y;
    cin >> t >> y;
    v.push_back(t);
    v1.push_back(y);
  }
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  int ans = n;
  for (int i = 0; i < n; i++) {
    ans += max(v[i], v1[i]);
  }
  cout << ans;
}
