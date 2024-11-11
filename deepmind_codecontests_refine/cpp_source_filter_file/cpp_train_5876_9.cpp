#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t, r;
  cin >> s;
  cin >> t;
  for (int i = s.length() - 1; i > 0; i--) {
    r += s[i];
  }
  if (r == t)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
