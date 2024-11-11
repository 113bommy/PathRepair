#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, len1, len2, r = 0, i, j;
  string s;
  vector<pair<char, int>> v;
  cin >> t;
  while (t--) {
    s.clear();
    v.clear();
    cin >> s;
    len1 = s.length();
    for (i = 0; i < len1; i++) {
      len2 = v.size();
      for (j = 0; j < len2; j++) {
        if (s[i] == v[j].first) {
          v[j].second += 1;
          break;
        }
      }
      if (j == len2) v.push_back(make_pair(s[i], 1));
    }
    len2 = v.size();
    r = 0;
    j = 0;
    for (i = 0; i < len2; i++) {
      if (v[i].second == 1)
        j++;
      else if (v[i].second >= 2)
        r++;
    }
    r += j / 2;
    cout << r << endl;
  }
  return 0;
}
