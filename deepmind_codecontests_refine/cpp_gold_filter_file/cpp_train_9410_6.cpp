#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<int> pos;
  int n = s.length();
  pos.push_back(-2);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '@') pos.push_back(i);
  }
  pos.push_back(n + 1);
  for (int i = 1; i < pos.size() - 1; ++i) {
    if (pos[i] - pos[i - 1] <= 2) {
      cout << "No solution\n";
      return 0;
    }
    if (pos[i + 1] - pos[i] <= 2) {
      cout << "No solution\n";
      return 0;
    }
  }
  if (pos.size() == 2) {
    cout << "No solution\n";
    return 0;
  }
  if (pos.size() == 3) {
    cout << s << '\n';
    return 0;
  }
  vector<string> str;
  str.push_back(s.substr(0, pos[1] + 2));
  for (int i = 2; i < pos.size() - 2; ++i) {
    string st = "";
    for (int idx = pos[i - 1] + 2; idx <= pos[i] + 1; ++idx) {
      st.push_back(s[idx]);
    }
    str.push_back(st);
  }
  string st = "";
  for (int idx = pos[pos.size() - 3] + 2; idx < n; ++idx) {
    st.push_back(s[idx]);
  }
  str.push_back(st);
  cout << str[0];
  for (int i = 1; i < str.size(); ++i) cout << ',' << str[i];
  cout << '\n';
}
