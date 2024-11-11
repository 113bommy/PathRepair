#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, n, x, k, p, t, c, d, m, p1, p2, p3;
  cin >> c >> d >> n >> m >> k;
  x = n * m - k;
  p1 = (x / n) * c + c;
  p2 = (x / n) * c + (x % n) * d;
  p3 = x * d;
  cout << min(0LL, min(p1, min(p2, p3)));
}
