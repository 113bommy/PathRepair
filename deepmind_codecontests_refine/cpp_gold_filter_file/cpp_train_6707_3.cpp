#include <bits/stdc++.h>
using namespace std;
using ll = int;
int n = -1, i, e, t, j;
int main() {
  string s;
  cin >> s;
  for (j = 0; j < s.size(); j++) {
    if (s[j] == 'n') {
      n++;
    }
    if (s[j] == 'i') {
      i++;
    }
    if (s[j] == 'e') {
      e++;
    }
    if (s[j] == 't') {
      t++;
    }
  }
  e /= 3;
  n /= 2;
  cout << min(min(n, i), min(e, t));
  return 0;
}
