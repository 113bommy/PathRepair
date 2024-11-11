#include <bits/stdc++.h>
using namespace std;
long long i, j, n, a[111], b, c, d, l, ll, r, s, t, k, m, xh, x, x1, y, z;
string p, q;
int main() {
  cin >> n >> d;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++)
      if (abs(a[i] - a[j]) <= d) t++;
  }
  t = t * 2;
  cout << t;
}
