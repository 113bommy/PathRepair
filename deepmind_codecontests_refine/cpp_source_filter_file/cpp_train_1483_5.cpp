#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(m);
  for (int& a : vec) cin >> a;
  long long suf[m + 1];
  suf[m] = 0;
  for (int i = m - 1; i >= 0; --i) suf[i] = vec[i] + suf[i + 1];
  if (suf[0] < n)
    cout << -1 << endl;
  else {
    int ans[m];
    int ind = 1;
    int fill = 0;
    bool pos = true;
    for (int i = 0; i < m; ++i) {
      while (max(fill, ind + vec[i] - 1) + suf[i + 1] < n) {
        fill = max(fill, ind + vec[i - 1]);
        ++ind;
      }
      if (ind > n - vec[i] + 1) pos = false;
      ans[i] = ind;
      ++ind;
    }
    if (pos) {
      for (int i = 0; i < m; ++i) cout << ans[i] << " ";
      cout << endl;
    } else
      cout << -1 << endl;
  }
}
