#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, c = 1;
  string s, t;
  cin >> s >> t;
  for (i = 0; i < t.length(); i++)
    if (s[c] == t[i]) c++;
  cout << c;
}
