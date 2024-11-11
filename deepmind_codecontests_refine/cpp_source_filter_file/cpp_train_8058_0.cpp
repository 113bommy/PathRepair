#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
const int INF = 1000000000;
int main() {
  int a, n, m;
  cin >> n >> m;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  vector<int> ans(n + 1, 0);
  set<int> s;
  for (int i = n - 1; i >= 0; i--) {
    int tmp = (int)s.size();
    s.insert(arr[i]);
    if (tmp != (int)s.size())
      ans[i] += (ans[i + 1] + 1);
    else
      ans[i] = ans[i + 1];
  }
  for (int i = 0; i < m; ++i) {
    cin >> a;
    a--;
    cout << ans[i] << endl;
  }
  return 0;
}
