#include <bits/stdc++.h>
using namespace std;
int occ[26];
int main() {
  string s, p;
  cin >> s >> p;
  int err = 0;
  if (s.size() < p.size()) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < p.size(); i++) {
    occ[p[i] - 'a']++;
  }
  for (int i = 0; i < p.size(); i++) {
    if (s[i] != '?') {
      occ[s[i] - 'a']--;
      if (occ[s[i] - 'a']) err++;
    }
  }
  int sol = 0;
  for (int i = 0; i <= s.size() - p.size(); i++) {
    if (err == 0) sol++;
    if (i + p.size() == s.size()) break;
    if (s[i] != '?') {
      occ[s[i] - 'a']++;
      if (occ[s[i] - 'a'] == 0) err--;
    }
    if (s[i + p.size()] != '?') {
      occ[s[i + p.size()] - 'a']--;
      if (occ[s[i + p.size()] - 'a'] == -1) err++;
    }
  }
  cout << sol << endl;
  return 0;
}
