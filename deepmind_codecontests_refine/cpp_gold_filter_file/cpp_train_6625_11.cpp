#include <bits/stdc++.h>
using namespace std;
string s1, s2;
vector<int> pos[30];
int res = 1, cur = -1;
int BSearch(char t) {
  t -= 'a';
  int l = 0, r = pos[t].size() - 1, m, vt = -1;
  while (l <= r) {
    m = (l + r + 1) >> 1;
    if (pos[t][m] > cur) {
      vt = pos[t][m];
      r = m - 1;
    } else
      l = m + 1;
  }
  return vt;
}
int main() {
  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); ++i) {
    pos[s1[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < s2.size(); ++i) {
    if (pos[s2[i] - 'a'].size() == 0) {
      cout << -1;
      return 0;
    }
    cur = BSearch(s2[i]);
    if (cur == -1) {
      --i;
      ++res;
      continue;
    }
  }
  cout << res;
  return 0;
}
