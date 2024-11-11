#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = (((1 << 30) - 1) << 1) + 1;
const int nINF = 1 << 31;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> k >> n;
  set<string> strset;
  vector<string> strs;
  for (int i = 0; i < (k); i++) {
    string str;
    cin >> str;
    strset.insert(str);
  }
  k = strset.size();
  for (auto& s : strset) strs.push_back(s);
  if (k == 1) {
    swap(strs[0][0], strs[0][1]);
    cout << strs[0] << endl;
    exit(0);
  }
  vector<int> f(26, 0);
  for (int i = 0; i < (n); i++) ++f[strs[0][i] - 'a'];
  for (auto& s : strs) {
    vector<int> tf(26, 0);
    for (int i = 0; i < (n); i++) ++tf[s[i] - 'a'];
    for (int i = 0; i < (26); i++) {
      if (f[i] != tf[i]) {
        cout << -1 << endl;
        exit(0);
      }
    }
  }
  vector<int> idxs;
  for (int i = 0; i < (n); i++) {
    if (strs[0][i] != strs[1][i]) idxs.push_back(i);
  }
  if (idxs.size() > 4) {
    cout << -1 << endl;
    exit(0);
  }
  set<string> poss;
  for (int i = 0; i < (idxs.size()); i++) {
    for (int j = 0; j < (n); j++) {
      string s = strs[0];
      swap(s[idxs[i]], s[j]);
      poss.insert(s);
    }
  }
  bool distinct = true;
  string temp = strs[0];
  sort(temp.begin(), temp.end());
  for (int i = 0; i < (n - 1); i++)
    if (temp[i] == temp[i + 1]) distinct = false;
  for (auto& s : poss) {
    bool good = true;
    for (int i = 0; i < (k); i++) {
      int cnt = 0;
      for (int j = 0; j < (n); j++)
        if (strs[i][j] != s[j]) ++cnt;
      if (cnt != 0 && cnt != 2) {
        good = false;
        break;
      }
      if (cnt == 0 && distinct) {
        good = false;
        break;
      }
    }
    if (!good) continue;
    cout << s << endl;
    exit(0);
  }
  cout << -1 << endl;
  return 0;
}
