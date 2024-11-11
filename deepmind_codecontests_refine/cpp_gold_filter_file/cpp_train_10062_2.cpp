#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > vl;
int main() {
  string s;
  cin >> s;
  int oi = -1;
  int l = 0;
  bool ok = true;
  for (int i = 0; i < s.length() && ok; i++) {
    if (s[i] == '0') {
      if (oi == -1) {
        vl.push_back(vector<int>());
        vl[l++].push_back(i);
      } else {
        vl[oi--].push_back(i);
      }
    } else {
      if (oi + 1 < l) {
        oi++;
        vl[oi].push_back(i);
      } else {
        ok = false;
      }
    }
  }
  ok &= oi == -1;
  if (!ok || vl.size() == 0)
    cout << -1 << endl;
  else {
    cout << vl.size() << endl;
    for (int i = 0; i < vl.size(); i++) {
      cout << vl[i].size() << ' ';
      for (int j = 0; j < vl[i].size(); j++) cout << vl[i][j] + 1 << ' ';
      cout << endl;
    }
  }
}
