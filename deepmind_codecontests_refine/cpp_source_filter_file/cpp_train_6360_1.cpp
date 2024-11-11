#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, rez, z, u;
int main() {
  cin >> n >> s >> t;
  for (int i = 0; i < n; ++i)
    if (s[i] == '0')
      ++z;
    else
      ++u;
  for (int i = 0; i < n; ++i)
    if (t[i] == '0') {
      if (s[i] == '0') {
        rez += u;
        --z;
      } else {
        rez += z;
        --u;
      }
    }
  cout << rez;
  return 0;
}
