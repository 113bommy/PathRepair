#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), ans;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    int x = a[i] + 1;
    while (x < a[i + 1] && m >= x) {
      ans.push_back(x);
      m -= x;
      ++x;
    }
    if (m < x) break;
  }
  for (int i = a[n] + 1; m >= i; ++i) {
    ans.push_back(i);
    m -= i;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
}
