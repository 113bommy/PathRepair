#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[n];
  map<string, int> m[n];
  map<string, int> m1;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < 9; j++) {
      string res;
      for (int k = j; k < 9; k++) {
        res += s[i][k];
        m[i][res]++;
        m1[res]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    string ans = s[i];
    for (auto it : m[i]) {
      if (it.second == m1[it.first])
        if (ans.size() > it.first.size()) ans = it.first;
    }
    cout << ans << '\n';
  }
  return 0;
}
