#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long n, c[110], a[110], b[110];
map<long long, long long> st;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  st[0] = 1;
  for (long long i = 2; i <= 105; i++) {
    st[i * (i - 1) / 2] = i;
  }
  long long w = n / 2;
  long long ix, iy, x, y;
  cin >> x >> y;
  ix = x, iy = y;
  for (long long i = 0; i < n - 3; i++) {
    long long tx, ty;
    cout << "+ " << n - 1 - i << endl;
    cin >> tx >> ty;
    c[n - i - 1] = ty - y;
    x = tx, y = ty;
    cout.flush();
  }
  long long tx, ty;
  cout << "+ 1" << endl;
  cin >> tx >> ty;
  c[1] = ty - y;
  x = tx, y = ty;
  cout << "+ 2" << endl;
  cin >> tx >> ty;
  c[2] = ty - y;
  x = tx, y = ty;
  cout << "+ 1" << endl;
  cin >> tx >> ty;
  b[1] = st[tx - x];
  c[0] = ty - y;
  a[1] = b[1] - 1;
  b[3] = c[0] - c[1];
  a[3] = b[3] - 1;
  b[2] = c[0] / b[3];
  a[2] = b[2] - 1;
  b[4] = (c[2] - (b[1] * b[3])) / b[3];
  a[4] = b[4] - 1;
  for (long long i = 5; i <= n; i++) {
    b[i] = (c[i - 2] - a[i - 3] * a[i - 4] - a[i - 3] * b[i - 1]) / b[i - 1];
    a[i] = b[i] - 1;
  }
  a[n++];
  cout << "!";
  for (long long i = 1; i < n + 1; i++) cout << " " << a[i];
  cout << endl;
  return 0;
}
