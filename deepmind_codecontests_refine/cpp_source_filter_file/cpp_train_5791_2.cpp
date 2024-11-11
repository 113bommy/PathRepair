#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_map<string, int> gg;
  int n;
  cin >> n;
  string ss[n];
  for (int i = 0; i < n; i++) {
    unordered_set<string> gg1;
    string s;
    cin >> s;
    ss[i] = s;
    for (int i = 0; i < s.size(); i++) {
      string hh;
      for (int j = i; j < s.size(); j++) {
        hh += s[j];
        if (!gg1.count(hh)) {
          gg[hh]++;
          gg1.insert(hh);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    bool f = 0;
    string& s = ss[i];
    for (int l = 1; l < s.size(); l++) {
      for (int j = 0; j < ((int)s.size()) - l + 1; j++) {
        string hh;
        for (int ll = 0; ll < l; ll++) {
          hh += s[j + ll];
          if (gg[hh] == 1) {
            f = 1;
            cout << hh << '\n';
            break;
          }
        }
        if (f) break;
      }
      if (f) break;
    }
  }
}
