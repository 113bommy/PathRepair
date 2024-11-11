#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> let[26];
int main() {
  int n, i, j, k;
  cin >> n >> k;
  cin >> s;
  for (i = 0; i < (int)s.length(); i++) {
    int c = s[i] - 'a';
    let[c].push_back(i);
  }
  for (i = 0; i < 26 && k; i++) {
    for (j = 0; j < k && let[i].size(); j++) {
      s[let[i][j]] = '#';
      k--;
    }
  }
  for (i = 0; i < s.length(); i++) {
    if (s[i] != '#') cout << s[i];
  }
  return 0;
}
