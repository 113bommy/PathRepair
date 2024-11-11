#include <bits/stdc++.h>
using namespace std;
int a, b, s, sum = 0, n, p1, p2, p3, t1, t2;
int fun(int x) {
  if (x <= t1) return x * p1;
  if (x <= t2 + t1)
    return (x - t1) * p2 + (p1 * t1);
  else
    return ((x - t1 - t2) * p3 + (p1 * t1) + (p2 * t2));
}
int main() {
  cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    if (i == 1) s = a;
    sum += fun(a - s) + (b - a) * p1;
    s = b;
  }
  cout << sum << endl;
  return 0;
}
