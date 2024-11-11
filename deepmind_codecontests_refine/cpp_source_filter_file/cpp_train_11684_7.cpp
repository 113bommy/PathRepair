#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5 + 10;
int a[SIZE];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0) ans.push_back(i);
    }
    if (ans.size()) {
      cout << 1 << endl << ans[0] << endl;
      continue;
    }
    if (n % 2) {
      cout << -1 << endl;
      continue;
    }
    cout << 2 << endl;
    cout << 1 << " " << 2 << endl;
  }
  return 0;
}
