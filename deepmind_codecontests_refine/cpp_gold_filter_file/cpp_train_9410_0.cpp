#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<char> t;
  t.push_back(',');
  for (int i = 0; i < s.size(); i++) {
    t.push_back(s[i]);
    if (s[i] == '@') {
      if (i != s.size() - 1) t.push_back(s[i + 1]), i++;
      t.push_back(',');
    }
  }
  int f = 1, ff = 0;
  for (int i = 0; f && i < t.size() - 1; i++) {
    if ((t[i] == '@' && t[i + 1] == '@') || (t[i] == '@' && t[i + 1] == ',') ||
        (t[i] == ',' && t[i + 1] == '@'))
      f = 0;
    if (t[i] == '@') ff = 1;
  }
  if (s[s.size() - 2] != '@')
    for (int i = t.size() - 1; i >= 0; i--)
      if (t[i] == ',') {
        t.erase(t.begin() + i, t.begin() + i + 1);
        break;
      }
  if (!f || !ff)
    cout << "No solution";
  else {
    int z = (t[t.size() - 1] == ',') ? t.size() - 1 : t.size();
    for (int i = 1; i < z; i++) cout << t[i];
  }
  return 0;
}
