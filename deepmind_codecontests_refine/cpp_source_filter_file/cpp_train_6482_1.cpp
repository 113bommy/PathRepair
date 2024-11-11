#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> ans(n, false);
    ans[n - 1] = true;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] > 1)
        ans[i] = true;
      else
        ans[i] = !ans[i + 1];
    }
    if (ans[0])
      cout << "First" << '\n';
    else
      cout << "Second" << '\n';
  }
}
