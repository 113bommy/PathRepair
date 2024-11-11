#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(m + 2);
  vector<int> ans;
  while (n--) {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
      vec[i]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (vec[i] == 0) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int i : ans) cout << i << " ";
  cout << endl;
  return 0;
}
