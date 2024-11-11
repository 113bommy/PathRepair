#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, cal, i, maxlo, maxhi;
  string str;
  char ch;
  cin >> n;
  maxlo = -100000000000;
  maxhi = 100000000000;
  for (i = 0; i < n; i++) {
    cal = getchar();
    cin >> str >> x >> ch;
    if (str == ">=") {
      if (ch == 'N') {
        if (maxhi > x) maxhi = x - 1;
      } else {
        if (maxlo < x) maxlo = x;
      }
    } else if (str == "<=") {
      if (ch == 'N') {
        if (maxlo < x) maxlo = x + 1;
      } else {
        if (maxhi > x) maxhi = x;
      }
    } else if (str == ">") {
      if (ch == 'N') {
        if (maxhi > x) maxhi = x;
      } else {
        if (maxlo < x) maxlo = x + 1;
      }
    } else if (str == "<") {
      if (ch == 'N') {
        if (maxlo < x) maxlo = x;
      } else {
        if (maxhi > x) maxhi = x - 1;
      }
    }
  }
  if (maxhi < maxlo)
    cout << "Impossible" << endl;
  else {
    if (maxhi <= -2000000000)
      cout << "Impossible" << endl;
    else if (maxlo >= 2000000000)
      cout << "Impossible" << endl;
    else if (maxhi <= 2000000000)
      cout << maxhi << endl;
    else if (maxlo >= -2000000000)
      cout << maxlo << endl;
  }
  return 0;
}
