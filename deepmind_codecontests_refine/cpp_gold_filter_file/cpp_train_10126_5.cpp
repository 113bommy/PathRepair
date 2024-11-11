#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  int t, n;
  string s;
  bool doable;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    map<char, int> appearances;
    for (int j = 0; j < n; j++) {
      cin >> s;
      for (int k = 0; k < s.size(); k++) {
        if (appearances.find(s[k]) == appearances.end())
          appearances[s[k]] = 1;
        else
          appearances[s[k]]++;
      }
    }
    doable = true;
    for (auto it = appearances.begin(); it != appearances.end(); it++) {
      if (it->second % n != 0) doable = false;
    }
    if (doable)
      cout << "YES";
    else
      cout << "NO";
    cout << "\n";
  }
}
