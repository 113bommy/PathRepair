#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string t;
  cin >> t;
  string s = "";
  bool check = false;
  int k;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == 'a') k = i;
  }
  for (int i = 0; i < t.size(); i++) {
    if (t[i] != 'a') s += t[i];
    if (t.substr(i + 1) == s && i >= k) {
      s = t.substr(0, i + 1);
      check = true;
      break;
    }
  }
  if (check)
    cout << s;
  else
    cout << ": (";
  return 0;
}
