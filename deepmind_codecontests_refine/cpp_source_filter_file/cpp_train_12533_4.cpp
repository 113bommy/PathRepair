#include <bits/stdc++.h>
using namespace std;
int main() {
  FILE* iFile = fopen("input.txt", "r");
  string s;
  cin >> s;
  set<char> diffS;
  map<char, list<int> > pos;
  int i = 0;
  for (string::iterator it = s.begin(); it != s.end(); ++it) {
    if (*it != '?' && (*it < '0' || *it > '9')) {
      diffS.insert(*it);
      pos[*it].push_back(i);
      ++i;
    }
  }
  if (diffS.size() > 10) {
    cout << "0" << endl;
    return 0;
  }
  long long res = 0;
  int charsLeft = 10;
  if (s[0] == '?') {
    res = 9;
  } else if ((s[0] >= '0') && (s[0] <= '9')) {
    res = 1;
  } else {
    res = 9;
    pos.erase(s[0]);
    --charsLeft;
  }
  string::iterator it = s.begin();
  while (true) {
    if (++it == s.end()) break;
    if (*it == '?')
      res *= charsLeft;
    else if (pos.find(*it) != pos.end()) {
      pos.erase(*it);
      res *= charsLeft--;
    }
  }
  cout << res << endl;
  return 0;
}
