#include <bits/stdc++.h>
using namespace std;
string s1, s2;
map<char, vector<int> > m;
int main() {
  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); ++i) m[s1[i]].push_back(i);
  int res = 1;
  int c = 0;
  for (int i = 0; i < s2.size(); ++i) {
    vector<int>::iterator it = lower_bound(m[s2[i]].begin(), m[s2[i]].end(), c);
    if (it == m[s2[i]].end()) {
      it = m[s2[i]].begin();
      res++;
    }
    if (it == m[s2[i]].end()) {
      res = -1;
      break;
    }
    c = *it + 1;
  }
  cout << res;
  return 0;
}
