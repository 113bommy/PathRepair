#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long> v;
  long n, b, i, a, ok = 0, max = -1;
  double pk;
  cin >> n >> b;
  for (i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
    ok += a;
    if (a > max) max = a;
  }
  ok += b;
  pk = (float)ok / n;
  if (max > pk) {
    cout << -1;
    return 0;
  }
  cout.setf(ios::fixed);
  cout.precision(7);
  for (i = 0; i < n; i++) cout << float(pk - v[i]) << endl;
  return 0;
}
