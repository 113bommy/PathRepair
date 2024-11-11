#include <bits/stdc++.h>
using namespace std;
const int N = 1e+5 + 10;
int q(const string &s) {
  cout << "? " << s << endl;
  int a;
  cin >> a;
  return a;
}
int main() {
  int n;
  cin >> n;
  string s = "";
  for (int i = 0; i < n; ++i) s += "0";
  int l, r;
  l = 0, r = n - 1;
  int cnt = q(s);
  while (l + 1 < r) {
    int m = (r - l + 1) / 2 + 1;
    for (int i = 0; i < m; ++i) {
      s[l + i] = '1';
    }
    if (abs(cnt - q(s)) != m) {
      r = l + m - 1;
    } else {
      l = r - m + 1;
    }
    for (int i = 0; i < n; ++i) {
      s[i] = '0';
    }
  }
  int pos0, pos1;
  for (int i = l; i <= r; ++i) {
    s[i] = '1';
    if (q(s) < cnt)
      pos1 = i;
    else
      pos0 = i;
    s[i] = '0';
  }
  cout << "! " << pos0 + 1 << ' ' << pos1 + 1 << endl;
  return 0;
}
