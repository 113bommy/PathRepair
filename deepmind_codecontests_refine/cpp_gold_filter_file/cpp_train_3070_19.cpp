#include <bits/stdc++.h>
using namespace std;
string s, t;
int x = 0, n, d = 0;
int main() {
  cin >> s >> t;
  n = s.size();
  for (int i = 0; i < n; i++)
    if (s[i] != t[i]) d++;
  if (d % 2 == 1) return cout << "impossible", 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i])
      cout << s[i];
    else if (x % 2 == 0)
      cout << s[i], x++;
    else
      cout << t[i], x++;
  }
  return 0;
}
