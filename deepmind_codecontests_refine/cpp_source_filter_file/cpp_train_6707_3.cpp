#include <bits/stdc++.h>
using namespace std;
using ll = int;
int n = -1, i, e, t, j;
int main() {
  string s;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'n') {
      n++;
    }
    if (s[i] == 'i') {
      i++;
    }
    if (s[i] == 'e') {
      e++;
    }
    if (s[i] == 't') {
      t++;
    }
  }
  e /= 3;
  n /= 2;
  cout << min(min(n, i), min(e, t));
  return 0;
}
