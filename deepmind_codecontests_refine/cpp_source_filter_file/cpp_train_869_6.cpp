#include <bits/stdc++.h>
using namespace std;
int n, m, s[5010], d[5010], r;
char z[99];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> s[i] >> z;
  for (int i = 1; i <= n; ++i) d[i] = -1;
  d[1] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      d[j + 1] = max(d[j + 1], d[j]), d[j] += (s[i] == j), r = max(r, d[j]);
  cout << n;
}
