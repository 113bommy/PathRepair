#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<pair<char, int>> sol;
  for (int i = 97; i < 123; i++) sol.push_back(make_pair(i, 0));
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < sol.size(); j++)
      if (s[i] == sol[j].first) sol[j].second++;
  }
  for (int i = sol.size(); i > -1; i--) {
    if (sol[i].second != 0) {
      for (int j = 0; j < sol[i].second; j++) cout << sol[i].first;
      break;
    }
  }
  return 0;
}
