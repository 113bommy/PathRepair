#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int N = 1e9;
long long int t, n, m;
long long int query(long long int x, long long int y) {
  cout << "? " << x << " " << y << endl;
  cin >> x;
  if (x == -1) exit(0);
  return x;
}
int main() {
  long long int i, j, k, x, y;
  long long int d1 = query(1, 1), d2 = query(N, 1), d3 = query(1, N);
  long long int a, b, c, d;
  x = (d1 - d2 + N + 1) / 2;
  b = query(x, 1) + 1;
  a = d1 - b + 2;
  d = a - 1 + N - d3;
  c = N - 1 + b - d2;
  cout << "! " << c << " " << d << " " << a << " " << b << endl;
  return 0;
}
