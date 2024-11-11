#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ans;
  int i = 0;
  while (i < n) {
    if (s[i] == 'B') {
      int cnt = 0;
      if (i == n - 1)
        ans.push_back(1), i++;
      else {
        while (s[i] != 'W') i++, cnt++;
        ans.push_back(cnt);
      }
    } else
      i++;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
