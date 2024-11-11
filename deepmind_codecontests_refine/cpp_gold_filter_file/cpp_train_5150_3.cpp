#include <bits/stdc++.h>
using namespace std;
const long maxn = 1001;
long a[maxn], n;
void init() {
  cin >> n;
  for (long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = 0;
}
void work() {
  double x = 0, y = a[n] * 20;
  for (long i = 0; i <= n - 1; i++) {
    double s, t;
    s = a[i + 1] * 10;
    s = s / (i + 1);
    t = (a[i + 1] + 1) * 10;
    t = t / (i + 1);
    if (s > x) x = s;
    if (t < y) y = t;
  }
  if (x < 10) x = 10;
  y = y - (1e-8);
  long p, q;
  p = long(((n + 1) * x) / 10);
  q = long(((n + 1) * y) / 10);
  if (p == q) {
    cout << "unique" << endl;
    cout << p << endl;
  } else
    cout << "not unique" << endl;
}
int main() {
  init();
  work();
  return 0;
}
