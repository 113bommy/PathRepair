#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, a, b, c, d, i, j, k, l, n, m, x, y;
  long long int x1, y1;
  cin >> x >> y >> x1 >> y1;
  a = max(x, x1);
  b = min(x, x1);
  c = max(y, y1);
  d = min(y, y1);
  x = b;
  x1 = a;
  y = d;
  y1 = c;
  l = 0;
  k = 0;
  long long int s[100000], v[100000];
  for (i = x; i <= x1; i++) {
    if (i == x || i == x1)
      j = 1;
    else
      j = y1 - y;
    for (t = y; t <= y1; t += j) {
      s[l] = i;
      v[l] = t;
      l++;
    }
  }
  map<pair<long long int, long long int>, long long int> dp;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    for (i = 0; i < l; i++) {
      d = abs(s[i] - a);
      j = abs(v[i] - b);
      m = sqrt((d * d) + (j * j));
      t = (d * d) + (j * j);
      if (t % m != 0) m++;
      if (m <= c) {
        dp[make_pair(s[i], v[i])] = 1;
      }
    }
  }
  for (i = 0; i < l; i++) {
    if (dp[make_pair(s[i], v[i])] == 0) k++;
  }
  cout << k;
}
