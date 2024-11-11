#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  vector<int> v[30];
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    v[c].push_back(i);
  }
  string resp = "";
  int last = 0;
  for (int i = 'z' - 'a'; i >= 'a' - 'a'; i--) {
    for (int j = 0; j < v[i].size(); j++) {
      int pos = v[i][j];
      if (pos > last) {
        resp += s[pos];
        last = pos;
      }
    }
  }
  cout << resp << endl;
  return 0;
}
