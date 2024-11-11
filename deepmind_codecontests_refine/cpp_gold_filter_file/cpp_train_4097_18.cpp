#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<char, vector<int> > m;
int main() {
  cin >> s;
  int i, j, k, l;
  for (i = 0; i < s.length(); i++) {
    m[s[i]].push_back(i);
  }
  k = -1;
  for (char h = 'z'; h >= 'a'; h--) {
    if (m[h].size() == 0) continue;
    for (j = 0; j < m[h].size(); j++) {
      if (m[h][j] > k) {
        cout << h;
        k = m[h][j];
      }
    }
  }
  cout << endl;
  return 0;
}
