#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int cnt = 2;
  vector<int> ans;
  if (n == 1)
    ans.push_back(1);
  else {
    ans.push_back(1);
    ans.push_back(2);
  }
  while (m > 0 && cnt < n) {
    cnt++;
    if ((cnt - 1) / 2 < m) {
      ans.push_back(cnt);
      m -= (cnt - 1) / 2;
    } else {
      ans.push_back(cnt + cnt - 1 - m - m);
      m = 0;
    }
  }
  int base = 100000;
  int interval = ans[ans.size() - 1] + 1;
  while (ans.size() < n) {
    ans.push_back(base);
    base += interval;
  }
  if (m != 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
