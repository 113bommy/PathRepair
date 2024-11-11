#include <bits/stdc++.h>
using namespace std;
int f(int a, int m) {
  if (a % m == 0) return m;
  return a % m;
}
int main() {
  int n, m;
  int a, b;
  cin >> n >> m >> a >> b;
  bool first = (a - 1) % m == 0;
  bool last = (b % m == 0) || (b == n);
  if (a - f(a, m) == b - f(b, m))
    cout << 1;
  else if (first && last)
    cout << 1;
  else if (first || last)
    cout << 2;
  else {
    if ((b + 1) % m == a % m)
      cout << 2;
    else {
      a -= f(a, m);
      a += m + 1;
      b -= f(b, m);
      if (b > a)
        cout << 3;
      else
        cout << 2;
    }
  }
  return 0;
}
