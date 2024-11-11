#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, r, l, p = 0, start, End;
  string str;
  cin >> n;
  cin >> str;
  r = 0, l = 0;
  for (i = 0; str[i]; i++) {
    if (str[i] != '.' && p == 0) {
      p = 1;
      start = i + 1;
    }
    if (str[i] == 'R')
      r++;
    else if (str[i] == 'L')
      l++;
    if (str[i] != '.' && str[i + 1] == '.' && i < n - 1) {
      End = i + 1;
    }
  }
  if (r == 0)
    cout << End << ' ' << start << endl;
  else if (l == 0)
    cout << start << ' ' << End + 1 << endl;
  else if (str[start - 1] == 'R') {
    cout << start << ' ';
    for (i = 0; i < n; i++)
      if (str[i] == 'L') break;
    cout << (i) << endl;
  }
  return 0;
}
