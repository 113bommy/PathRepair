#include <bits/stdc++.h>
using namespace std;
string st;
int d[20], m;
bool test(int b) {
  bool before = 1;
  int be = 0, af = 0, p = 1;
  for (int i = ((int)((st).size())) - 1; i >= 0; i--) {
    if (st[i] == ':') {
      before = 0;
      p = 1;
      continue;
    }
    if (before)
      be += p * d[i];
    else
      af += p * d[i];
    p *= b;
  }
  return (be < 60 && be >= 0 && af < 24 && af >= 0);
}
int main() {
  cin >> st;
  for (int i = 0; i < ((int)((st).size())); ++i) {
    if (st[i] == ':') continue;
    if (isdigit(st[i]))
      d[i] = st[i] - '0';
    else if (st[i] >= 'A' && st[i] <= 'Z')
      d[i] = st[i] - 'A' + 10;
    m = max(m, d[i]);
  }
  int t = m;
  while (1) {
    if (m > 70) {
      cout << -1;
      return 0;
    }
    if (!test(m)) {
      if (t == m)
        cout << 0;
      else {
        for (int i = t; i < m; i++) cout << i << " ";
      }
      return 0;
    }
    m++;
  }
}
