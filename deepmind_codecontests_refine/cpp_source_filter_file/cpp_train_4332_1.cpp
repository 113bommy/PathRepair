#include <bits/stdc++.h>
using namespace std;
string s, t;
map<char, int> used, needed;
inline bool check() {
  for (map<char, int>::iterator it = used.begin(); it != used.end(); it++) {
    if (it->second < needed[it->first]) {
      return false;
    }
  }
  for (map<char, int>::iterator it = used.begin(); it != used.end(); it++) {
    it->second %= needed[it->first];
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  for (int i = 0; i < t.size(); i++) {
    needed[t[i]]++;
    used[t[i]] = 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (needed[s[i]]) {
      used[s[i]]++;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      while (check()) {
      }
      for (map<char, int>::iterator it = used.begin(); it != used.end(); it++) {
        if (it->second < needed[it->first]) {
          s[i] = it->first;
          it->second++;
          break;
        }
      }
    }
  }
  cout << s;
}
