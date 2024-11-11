#include <bits/stdc++.h>
#pragma hdrstop
using namespace std;
void solve();
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
int n, m, k;
int d[200];
int val[200];
int koch[200];
void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) cin >> d[i];
  for (int i = 0; i < k; i++) {
    cin >> koch[i];
    for (int j = 0; j < m; j++)
      if (koch[i] % d[j] == 0) val[j]++;
  }
  int mn = 1 << 30;
  for (int i = 0; i < m; i++) mn = min(mn, val[i]);
  vector<int> ans;
  for (int i = 0; i < m; i++)
    if (val[i] == mn) ans.push_back(i + 1);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}
