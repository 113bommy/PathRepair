#include <bits/stdc++.h>
using namespace std;
int i, j, k, m, n, ln, nn, ar[100005], tc, mx, cnt;
vector<string> vs;
string s, s1, s2;
map<string, bool> mp;
int main() {
  while (cin >> nn) {
    vs.clear();
    mp.clear();
    while (nn--) {
      cin >> s;
      ln = s.size();
      for (i = 0; i < ln; i++) {
        s1 = "";
        m = ln - i;
        for (j = 1; j <= m; j++) {
          s1 = s.substr(i, j);
          vs.push_back(s1);
          mp[s1] = true;
        }
      }
    }
    bool g = 0;
    for (i = 97; i < 122; i++) {
      s1 = "";
      s1 += (char)i;
      if (!mp[s1]) {
        cout << s1 << endl;
        g = 1;
        break;
      }
    }
    if (!g) {
      bool f = 0;
      for (i = 97; i <= 122; i++) {
        for (j = i + 1; j <= 122; j++) {
          s1 = "";
          s1 += (char)i;
          s1 += (char)j;
          if (!mp[s1]) {
            cout << s1 << endl;
            f = 1;
            break;
          }
        }
        if (f) break;
      }
    }
  }
  return 0;
}
