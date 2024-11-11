#include <bits/stdc++.h>
using namespace std;
long long int dec(string s, int n) {
  long long int r = 0, p = 0, l = s.size() - 1, tmp;
  while (l >= 0) {
    if (isalpha(s[l]))
      tmp = s[l] - 55;
    else
      tmp = s[l] - 48;
    int prod = 1;
    for (int k = 0; k < p; k++) prod *= n;
    r += prod * tmp;
    p++;
    l--;
  }
  return r;
}
int main() {
  string s, a, b;
  int mx = 0;
  cin >> s;
  int i = 0;
  while (s[i] != ':') {
    a.push_back(s[i]);
    if (mx < s[i]) mx = s[i];
    i++;
  }
  i++;
  while (s[i] != '\0') {
    b.push_back(s[i]);
    if (mx < s[i]) mx = s[i];
    i++;
  }
  int bg;
  bg = mx < 65 ? mx - 48 : mx - 55;
  int beg = max(2, bg + 1);
  if (dec(a, beg) >= 24 || dec(b, beg) >= 60) {
    cout << 0 << endl;
    return 0;
  }
  if (dec(a, 100) < 24 && dec(b, 100) < 60) {
    cout << -1 << endl;
    return 0;
  }
  for (i = beg; i < mx; i++) {
    if (dec(a, i) < 24 && dec(b, i) < 60) {
      cout << i << " ";
    } else
      break;
  }
  return 0;
}
