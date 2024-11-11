#include <bits/stdc++.h>
using namespace std;
const long long MAX = 100, INF = 1 << 30;
long long a, b;
int main() {
  long long n1, n2, ta, tb;
  while (cin >> ta >> tb) {
    n1 = n2 = 0;
    a = ta;
    b = tb;
    while (a != b) {
      if (a < b) {
        ++n1;
        a += ta;
      } else {
        ++n2;
        b += tb;
      }
    }
    if (a < b)
      ++n1;
    else
      ++n2;
    if (n1 > n2)
      cout << "Dasha" << endl;
    else if (n1 < n2)
      cout << "Masha" << endl;
    else
      cout << "Equal" << endl;
  }
  return 0;
}
