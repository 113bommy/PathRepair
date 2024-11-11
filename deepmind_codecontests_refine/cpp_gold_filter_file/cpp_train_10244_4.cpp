#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long x;
  long long y;
  cin >> x >> y;
  string s;
  cin >> s;
  long long sumx = 0, sumy = 0;
  bool res = 1;
  if (x == 0 && y == 0) {
    cout << "Yes";
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'U') {
      sumy++;
    } else if (s[i] == 'D') {
      sumy--;
    } else if (s[i] == 'R') {
      sumx++;
    } else {
      sumx--;
    }
  }
  long long xx = 0;
  long long yy = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'U') {
      yy++;
    } else if (s[i] == 'D') {
      yy--;
    } else if (s[i] == 'R') {
      xx++;
    } else {
      xx--;
    }
    long long ss = 0;
    if (sumx != 0 && (x - xx) / sumx > 0) {
      ss = (x - xx) / sumx;
    } else if (sumy != 0 && (y - yy) / sumy > 0) {
      ss = (y - yy) / sumy;
    }
    if (xx + sumx * ss == x && yy + sumy * ss == y) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
