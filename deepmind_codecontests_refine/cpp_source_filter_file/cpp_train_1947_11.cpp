#include <bits/stdc++.h>
using namespace std;
int main(void) {
  float x, y, m, n;
  cin >> x >> y;
  if (x == y)
    cout << "=";
  else {
    m = y * log10(x);
    n = x * log10(y);
    if (m > n)
      cout << ">";
    else if (m < n)
      cout << "<";
    else
      cout << "=";
  }
}
