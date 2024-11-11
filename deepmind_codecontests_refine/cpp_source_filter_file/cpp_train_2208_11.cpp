#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 4;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;
    for (int i = 0; i < n - 2; i++) {
      if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
        ans.push_back(i + 1);
      }
      if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
        if (s[i + 3] == 'n' && s[i + 4] == 'e' && i + 4 < n) {
          ans.push_back(i + 2);
          i = i + 2;
        } else
          ans.push_back(i + 1);
      }
    }
    if (ans.size() == 0)
      cout << "0\n\n";
    else {
      cout << ans.size() << endl;
      for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
      cout << endl;
    }
  }
}
