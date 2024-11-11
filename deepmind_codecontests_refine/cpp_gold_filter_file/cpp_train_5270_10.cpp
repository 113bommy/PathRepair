#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  vector<string> res;
  int left = 0;
  int right = 0;
  bool bad = false;
  int badcount = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != 'a' && s[i] != 'e' && s[i] != 'o' && s[i] != 'i' &&
        s[i] != 'u') {
      badcount++;
    } else {
      badcount = 0;
    }
    if (badcount >= 3) {
      if (!(s[i] == s[i - 1] && s[i] == s[i - 2])) {
        bad = true;
      }
    }
    if (bad) {
      res.push_back(s.substr(left, i - left));
      left = i;
      i--;
      bad = false;
      badcount = 0;
      continue;
    }
    if (i == s.size() - 1) {
      res.push_back(s.substr(left, s.size() - left));
    }
  }
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}
