#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = 0, r = 0;
  for (char c : s) {
    if (c == '-')
      l++;
    else
      r++;
  }
  if (r == 0 || l % r == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
