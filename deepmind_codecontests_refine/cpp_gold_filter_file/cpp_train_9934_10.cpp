#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, m1, h2, m2;
  char ch;
  cin >> h1 >> ch >> m1;
  cin >> h2 >> ch >> m2;
  if (m2 > m1) {
    m1 += 60;
    if (h2 >= h1)
      h1 += 23;
    else
      h1--;
  } else {
    if (h2 > h1) h1 += 24;
  }
  int res1 = h1 - h2;
  int res2 = m1 - m2;
  if (res1 < 10) {
    if (res2 < 10)
      cout << "0" << res1 << ":"
           << "0" << res2;
    else
      cout << "0" << res1 << ":" << res2;
  } else {
    if (res2 < 10)
      cout << res1 << ":"
           << "0" << res2;
    else
      cout << res1 << ":" << res2;
  }
  return 0;
}
