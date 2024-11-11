#include <bits/stdc++.h>
using namespace std;
const long long max_n = 1e6 + 5;
long long n, m;
vector<string> g;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  g.resize(n);
  for (long long z = 0; (1 > 0 and z < n) or (1 < 0 and z > n); z += 1)
    cin >> g[z];
  ;
  if (n > m) {
    vector<string> b(m);
    for (long long i = 0; (1 > 0 and i < m) or (1 < 0 and i > m); i += 1)
      for (long long j = 0; (1 > 0 and j < n) or (1 < 0 and j > n); j += 1)
        b[i].push_back(g[j][i]);
    g = b;
    swap(n, m);
  }
  vector<vector<long long> > a(n, vector<long long>(m));
  for (long long i = 0; (1 > 0 and i < n) or (1 < 0 and i > n); i += 1)
    for (long long j = 0; (1 > 0 and j < m) or (1 < 0 and j > m); j += 1)
      a[i][j] = g[i][j] - '0';
  long long ans = n * m;
  if (n > 3)
    ans = -1;
  else if (n == 1)
    ans = 0;
  else if (n == 2) {
    for (long long x = 0; (1 > 0 and x < 2) or (1 < 0 and x > 2); x += 1) {
      long long cntr = 0;
      for (long long i = 0; (1 > 0 and i < m) or (1 < 0 and i > m); i += 1)
        if (((i & 1) ^ x) != (a[0][i] ^ a[1][i])) ++cntr;
      ans = min(ans, cntr);
    }
  } else {
    for (long long x = 0; (1 > 0 and x < 2) or (1 < 0 and x > 2); x += 1) {
      for (long long y = 0; (1 > 0 and y < 2) or (1 < 0 and y > 2); y += 1) {
        long long cntr = 0;
        for (long long i = 0; (1 > 0 and i < m) or (1 < 0 and i > m); i += 1)
          if (((i & 1) ^ x) != (a[0][i] ^ a[1][i]) or
              ((i & 1) ^ y) != (a[1][i] ^ a[2][i]))
            ++cntr;
        ans = min(ans, cntr);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
