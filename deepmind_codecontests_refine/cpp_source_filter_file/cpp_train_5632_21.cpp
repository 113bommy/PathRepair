#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> ans;
bool check(int m, int n) {
  if (m == 0) return true;
  int i = 0;
  int ans1 = 0;
  while (i < ans.size()) {
    ans1 += ans[i] / m;
    i++;
  }
  return ans1 >= n;
}
int main() {
  int n, m, l;
  cin >> n >> m;
  map<int, int> mp;
  for (int i = 0; i < m; i++) {
    cin >> l;
    mp[l]++;
  }
  for (auto elem : mp) {
    ans.push_back(elem.second);
  }
  sort(ans.begin(), ans.end());
  l = 0;
  int r = m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (check(m, n)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l;
  return 0;
}
