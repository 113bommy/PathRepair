#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p[n];
    for (int &i : p) cin >> i;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (i == 0 || i == n - 1 || (p[i - 1] < p[i]) != (p[i] < p[i + 1]))
        ans.push_back(p[i]);
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;
  }
}
