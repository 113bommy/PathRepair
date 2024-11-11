#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, h2, m1, m2, h3, m3;
  char c;
  cin >> h1 >> c >> m1;
  cin >> h2 >> c >> m2;
  if (m1 - m2 < 0) {
    h1--;
    m3 = 60 - (m2 - m1);
  } else
    m3 = m1 - m2;
  if (h1 - h2 < 0)
    h3 = 24 - (h2 - h1);
  else
    h3 = h1 - h2;
  if (h3 / 10 == 0)
    cout << 0 << h3;
  else
    cout << h3;
  cout << ":";
  if (m3 / 10 == 0)
    cout << 0 << m3;
  else
    cout << m3;
  return 0;
}
