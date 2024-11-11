#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  map<int, string> mp;
  map<string, int> mp2;
  string ans = "";
  string pol = "";
  bool flag = false;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    bool polindrom = false;
    for (int j = 0; !flag && j < (m + 1) / 2; j++) {
      if (s[j] != s[m - j - 1]) {
        polindrom = false;
        break;
      }
      polindrom = true;
    }
    if (polindrom) {
      flag = true;
      pol = s;
    } else {
      string rev = s;
      reverse(rev.begin(), rev.end());
      if (mp2.find(rev) != mp2.end()) ans.push_back(i);
    }
    mp[i] = s;
    mp2[s] = i;
  }
  if (ans.size() == 0 && !flag) {
    cout << 0 << "\n";
    return 0;
  }
  cout << ans.size() * 2 * m + pol.size() << "\n";
  for (int i = 0; i < ans.size(); i++) cout << mp[ans[i]];
  if (flag) cout << pol;
  for (int i = ans.size() - 1; i >= 0; i--) {
    string st = mp[ans[i]];
    reverse(st.begin(), st.end());
    cout << st;
  }
  cout << "\n";
  return 0;
}
