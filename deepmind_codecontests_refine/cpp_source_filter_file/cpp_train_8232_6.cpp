#include <bits/stdc++.h>
using namespace std;
long long n, h, a, b, q, t1, t2, f1, f2, m1, m2;
int main() {
  cin >> n >> h >> a >> b >> q;
  while (q--) {
    cin >> t1 >> f1 >> t2 >> f2;
    if (t1 == t2) {
      cout << abs(f2 - f1) << endl;
      continue;
    }
    int lewo = 0;
    int prawo = 0;
    if (f1 >= a and b >= f1) {
      lewo = 0;
      m1 = f1;
    } else {
      if (f1 > b) {
        lewo = f1 - b;
        m1 = b;
      } else {
        lewo = a - f1;
        m1 = a;
      }
    }
    if (f2 >= a and b >= f2) {
      lewo = 0;
      m2 = f2;
    } else {
      if (f2 > b) {
        prawo = f2 - b;
        m2 = b;
      } else {
        prawo = a - f2;
        m2 = a;
      }
    }
    cout << abs(t2 - t1) + lewo + prawo + abs(m2 - m1) << endl;
  }
  return 0;
}
