#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, o = 0, l = 0;
  string s;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o')
      o++;
    else
      l++;
  }
  if (o == 0)
    cout << "NO\n";
  else if (l % o == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
}
