#include <bits/stdc++.h>
using namespace std;
string s, t;
int a, b, c;
int main() {
  cin >> s >> t;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i] && s[i] == '4') {
      a++;
      c++;
    } else if (s[i] != t[i] && s[i] == '7') {
      b++;
      c++;
    }
  }
  cout << c - (min(a, b) / 2);
  return 0;
}
