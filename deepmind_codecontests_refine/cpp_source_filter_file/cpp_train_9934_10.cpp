#include <bits/stdc++.h>
using namespace std;
int main() {
  int m1, m2, h1, h2;
  char c;
  cin >> h1 >> c >> m1 >> c >> h2 >> c >> m2;
  int sum1 = h1 * 60 + m1;
  int sum2 = h2 * 60 + m2;
  sum1 -= sum2;
  if (sum1 < 0) sum1 += 24 * 60;
  h1 = sum1 / 60;
  m1 = sum1 %= 60;
  if (h1 < 10) cout << 0;
  cout << h1 << ":";
  if (m1 < 10) cout << 0;
  cout << m1 << endl;
  return 0;
}
