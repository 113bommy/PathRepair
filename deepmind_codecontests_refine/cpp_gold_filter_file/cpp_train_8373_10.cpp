#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  string t;
  getline(cin, t);
  int upp[26] = {0}, low[26] = {0};
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      low[s[i] - 'a']++;
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
      upp[s[i] - 'A']++;
    }
  }
  for (int i = 0; i < t.size(); i++) {
    if (t[i] >= 'a' && t[i] <= 'z') {
      low[t[i] - 'a']--;
    } else if (t[i] >= 'A' && t[i] <= 'Z') {
      upp[t[i] - 'A']--;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (low[i] < 0 || upp[i] < 0) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
