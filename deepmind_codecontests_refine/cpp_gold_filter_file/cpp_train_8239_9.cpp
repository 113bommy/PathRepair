#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, totAll = 0, tot = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    totAll += a[i];
  }
  tot = a[0];
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    if (a[0] >= 2 * a[i]) {
      tot += a[i];
      ans.push_back(i + 1);
    }
  }
  if (2 * tot > totAll) {
    cout << ans.size() + 1 << endl;
    cout << 1;
    for (auto it : ans) cout << " " << it;
    cout << endl;
  } else {
    cout << 0 << endl;
  }
}
