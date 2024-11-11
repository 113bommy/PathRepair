#include <bits/stdc++.h>
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
using namespace std;
char tr[1005];
int main() {
  int len;
  cin >> len;
  scanf("%s", tr);
  int lR, rR, lL, rL;
  lR = lL = INF;
  rR = rL = -1;
  for (int i = 0; i < len; i++) {
    if (tr[i] == 'R') {
      lR = ((lR) < (i) ? (lR) : (i));
      rR = ((rR) > (i) ? (rR) : (i));
    }
    if (tr[i] == 'L') {
      lL = ((lL) < (i) ? (lL) : (i));
      rL = ((rL) > (i) ? (rL) : (i));
    }
  }
  if (rL == -1) {
    cout << lR + 1 << " " << rR + 1 + 1 << endl;
  } else if (rR == -1) {
    cout << rL + 1 << " " << lL - 1 + 1 << endl;
  } else {
    cout << lR + 1 << " " << rR + 1 << endl;
  }
  return 0;
}
