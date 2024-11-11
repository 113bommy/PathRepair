#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, j;
  cin >> n >> m;
  map<string, string> mp;
  string s1, s2;
  for (i = 0; i < m; i++) {
    cin >> s1 >> s2;
    mp[s1] = s2;
  }
  vector<string> ans;
  for (i = 0; i < n; i++) {
    cin >> s1;
    if (s1.length() <= mp[s1].length()) {
      ans.push_back(s1);
    } else {
      ans.push_back(mp[s1]);
    }
  }
  for (i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
