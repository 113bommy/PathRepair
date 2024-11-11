#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n + 1, 0), a(n + 1, 0);
  vector<int> cntf(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cntf[a[i]]++;
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (v[i] == 1) {
      vector<int> temp;
      int cur = i;
      temp.push_back(cur);
      cur = a[cur];
      while (cur > 0 && cntf[cur] == 1) {
        temp.push_back(cur);
        cur = a[cur];
      }
      if (ans.size() < temp.size()) {
        ans = temp;
      }
    }
  }
  cout << ans.size() << endl;
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
