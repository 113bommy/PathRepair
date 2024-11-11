#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, l, m;
  cin >> n >> k;
  string s;
  cin >> s;
  l = 0;
  j = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == 'G') l = i;
    if (s[i] == 'T') j = i;
  }
  m = 0;
  int fo = 0;
  if (l > j) {
    for (i = l; i >= 0; i = i - k) {
      if (s[i] == '#') {
        m = 1;
        break;
      }
      if (s[i] == 'T') {
        fo = 1;
        break;
      }
    }
    if (fo == 1)
      cout << "YES";
    else
      cout << "NO";
  } else {
    for (i = l; i < n; i = i + k) {
      if (s[i] == '#') {
        m = 1;
        break;
      }
      if (s[i] == 'T') {
        fo = 1;
        break;
      }
    }
    if (fo == 1)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
