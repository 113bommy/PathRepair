#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a = 0, b = 0, c, d, e, f = 999999999, l, g, m, n, k, i, j, t, p, q;
  cin >> n;
  vector<long long> v;
  for (i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  for (i = 1; i < 120; i++) {
    a = 0;
    for (j = 0; j < n; j++) {
      c = abs(i - v[j]) - 1;
      if (c < 0) c = 0;
      a += c;
    }
    if (a < f) {
      f = a;
      b = i;
    }
  }
  cout << b << ' ' << f << endl;
  return 0;
}
