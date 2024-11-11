#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, t;
  cin >> n >> a >> b >> c;
  if (n == 1)
    cout << "0" << endl;
  else {
    if (a < c && a <= b) t = (n - 1) * a;
    if (b < c && b <= a) t = (n - 1) * b;
    if (c < a && c < b) {
      if (a <= b)
        t = a + (n - 2) * c;
      else
        t = b + (n - 2) * c;
    }
    cout << t << endl;
  }
  return 0;
}
