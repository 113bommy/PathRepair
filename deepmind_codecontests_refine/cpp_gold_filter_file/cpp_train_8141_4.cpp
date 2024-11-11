#include <bits/stdc++.h>
using namespace std;
int t;
string s;
vector<int> v;
int main() {
  cin >> t;
  while (t--) {
    v.clear();
    cin >> s;
    int n = s.size();
    int ans = 0;
    s += "111111111";
    for (int i = 0; i < n; i++) {
      if (s[i] == 't') {
        if (s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' &&
            s[i + 4] == 'e') {
          ans++;
          v.push_back(i + 2);
          i = i + 4;
        } else {
          if (s[i + 1] == 'w' && s[i + 2] == 'o') {
            ans++;
            v.push_back(i + 1);
            i += 2;
          }
        }
      } else {
        if (s[i] == 'o') {
          if (s[i + 1] == 'n' && s[i + 2] == 'e') {
            ans++;
            v.push_back(i + 1);
            i += 2;
          }
        }
      }
    }
    cout << ans << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] + 1 << ' ';
    }
    cout << endl;
  }
  return 0;
}
