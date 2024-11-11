#include <bits/stdc++.h>
using namespace std;
int main() {
  int m1, m2, m3, a, b, c, n;
  cin >> n;
  cin >> m1 >> a >> m2 >> b >> m3 >> c;
  while (m1 + m2 + m3 != n) {
    if (m1 != a)
      m1++;
    else if (m2 != b)
      m2++;
    else if (m3 != c)
      m3++;
  }
  cout << m1 << " " << m2 << " " << m3 << endl;
  return 0;
}
