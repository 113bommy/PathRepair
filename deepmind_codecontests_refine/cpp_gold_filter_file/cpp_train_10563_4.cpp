#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string s, s1;
  vector<string> strings, strings1;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> s >> s1;
    if (s1.size() >= s.size()) {
      strings.push_back(s1);
      strings1.push_back(s);
    } else {
      strings.push_back(s);
      strings1.push_back(s1);
    }
  }
  bool hasDone = 0;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s == strings.at(j)) {
        if (i != n - 1)
          cout << strings1.at(j) << " ";
        else
          cout << strings1.at(j);
        hasDone = 1;
      }
    }
    if (hasDone == 0) {
      if (i != n - 1)
        cout << s << " ";
      else
        cout << s;
    }
    hasDone = 0;
  }
}
