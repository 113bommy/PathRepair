#include <bits/stdc++.h>
using namespace std;
int r[100005], r2[100006];
int main() {
  long long int a, b, c, d, e, f, g, h, i, j, k;
  vector<int> v;
  while (cin >> a) {
    for (b = 1; b <= a; b++) {
      cin >> c;
      v.push_back(c);
    }
    sort(v.begin(), v.end());
    d = a / 2.;
    e = 0;
    f = 0;
    for (g = 0; g < d; g++) {
      e += v[g];
    }
    for (g = d; g < a; g++) {
      f += v[g];
    }
    long long int zz = (f * f) + (e * e);
    cout << zz << endl;
    v.clear();
  }
  return 0;
}
