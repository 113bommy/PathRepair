#include <bits/stdc++.h>
using namespace std;
long long int a, b, x1, y, x2, y2;
int main() {
  cin >> a >> b >> x1 >> y >> x2 >> y2;
  long long int da;
  long long int k1 = x1 + y;
  long long int k2 = x2 + y2;
  long long int mi = min(k1, k2);
  long long int ma = max(k1, k2);
  long long int c = mi % (2 * a);
  if (c < 0) c += 2 * b;
  if (c != 0) mi += 2 * a - c;
  c = ma % (2 * a);
  if (c < 0) c += 2 * b;
  ma -= c;
  if (mi > ma)
    da = 0;
  else
    da = (ma - mi) / (2 * a) + 1;
  long long int db;
  long long int t1 = x1 - y;
  long long int t2 = x2 - y2;
  mi = min(t1, t2);
  ma = max(t1, t2);
  c = mi % (2 * b);
  if (c < 0) c += 2 * b;
  if (c != 0) mi += 2 * b - c;
  c = ma % (2 * b);
  if (c < 0) c += 2 * b;
  ma -= c;
  if (mi > ma)
    db = 0;
  else
    db = (ma - mi) / (2 * b) + 1;
  cout << max(da, db);
}
