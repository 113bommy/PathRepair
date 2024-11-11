#include <bits/stdc++.h>
using namespace std;
string s[3];
vector<int> a[3];
int main() {
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    if (s[i] == "rock")
      s[i] = 'r';
    else if (s[i] == "scissors")
      s[i] = 's';
    else
      s[i] = 'p';
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == j) continue;
      if (s[i] == "s" && s[j] == "p")
        a[i].push_back(j);
      else if (s[i] == "p" && s[j] == "r")
        a[i].push_back(j);
      else if (s[i] == "r" && s[j] == "s")
        a[i].push_back(j);
    }
  }
  int ans = 0;
  int t = 0;
  for (int i = 0; i < 3; i++) {
    if (a[i].size() == 2) {
      ans++;
      t = i;
    }
  }
  if (ans != 1)
    cout << '?';
  else {
    if (t == 0)
      cout << 'F';
    else if (t == 1)
      cout << 'M';
    else
      cout << 'S';
  }
  return 0;
}
