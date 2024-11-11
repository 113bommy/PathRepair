#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1[1001], a2[1001], b = 0, c1 = 0, c2 = 0, d, n, m, i = 1;
  cin >> n;
  if (n < 3) {
    cout << 1 << endl;
    cout << n;
  } else {
    d = n;
    while (n >= i) {
      n -= i;
      c1++;
      a1[c1 - 1] = i;
      i++;
    }
    a1[c1 - 1] += n;
    m = 2;
    while (d >= m) {
      d -= m;
      c2++;
      a2[c2 - 1] = m;
      m++;
    }
    a2[c2 - 1] += d;
    if (c1 > c2) {
      cout << c1 << endl;
      cout << a1[0];
      for (int i = 1; i < c1; i++) cout << " " << a1[i];
    } else {
      cout << c2 << endl;
      cout << a2[0];
      for (int i = 1; i < c2; i++) cout << " " << a2[i];
    }
  }
  return 0;
}
