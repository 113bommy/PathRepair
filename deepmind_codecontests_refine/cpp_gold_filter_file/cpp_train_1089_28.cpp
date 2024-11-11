#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int h, n, m, d, t = 0, h1, l;
  cin >> h >> n;
  h1 = h;
  m = pow(2, h) - 1;
  m += n;
  while (m != 1) {
    n = m - (pow(2, h)) + 1;
    if (m == 2)
      d = 2;
    else if (m == 3)
      d = 0;
    else
      d = n % 4;
    switch (d) {
      case 0:
      case 1:
        l = h1 - h + 1;
        t += pow(2, l);
        break;
      case 3:
      case 2:
        t += 1;
    }
    m /= 2;
    h--;
  }
  cout << t << endl;
  return 0;
}
