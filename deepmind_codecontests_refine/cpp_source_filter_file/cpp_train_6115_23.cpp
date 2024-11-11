#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> ans;
  int n;
  int m;
  cin >> n >> m;
  int a[110];
  int b[20];
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    b[t] = 1;
  }
  for (int i = 0; i < 10; i++) {
    if (b[a[i]] == 1) ans.push_back(a[i]);
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
