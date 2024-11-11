#include <bits/stdc++.h>
using namespace std;
long long int powe(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int p = powe(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return (b % a, a);
}
int main() {
  int d1, d2, i, n, j, a, x[3], y[3];
  for (int(i) = (0); (i) <= (2); ++i) cin >> x[i] >> y[i];
  set<int> s;
  for (int(i) = (0); (i) <= (2); ++i) {
    d1 = x[(i + 1) % 3] - x[(i + 2) % 3];
    d2 = y[(i + 1) % 3] - y[(i + 2) % 3];
    a = x[i] - d1 + 4000;
    a *= 10000;
    a += y[i] - d2 + 4000;
    s.insert(a);
    a = d1 + x[i] + 4000;
    a *= 10000;
    a += d2 + y[i] + 4000;
    s.insert(a);
  }
  cout << s.size() << endl;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    d1 = *it / 10000 - 4000;
    d2 = (*it % 10000) - 4000;
    cout << d1 << " " << d2 << endl;
  }
  return 0;
}
