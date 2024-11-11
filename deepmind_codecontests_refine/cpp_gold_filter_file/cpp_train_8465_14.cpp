#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;
int main() {
  long long i, j, n, m, a, b;
  char c;
  cin >> n >> m;
  long long *d = new long long[n + 2];
  memset(d, 0, (n + 2) * sizeof(long long));
  long long *g = new long long[n + 2];
  memset(g, 0, (n + 2) * sizeof(long long));
  long long *r = new long long[n + 2];
  r[0] = 1;
  for (i = 1; i <= n; ++i) r[i] = 5 * r[i - 1];
  for (i = 0; i < m; ++i) {
    cin >> a >> b;
    d[a] += r[b];
    d[b] += r[a];
  }
  for (i = 0; i < n + 2; ++i) g[i + 1] = d[i + 1] + r[i + 1];
  long long sum = 0, prev = 0;
  sort(g + 1, g + n + 1);
  for (i = 1; i <= n; ++i) {
    if (g[i] == g[i - 1]) {
      sum += prev++;
    } else
      prev = 1;
  }
  prev = 0;
  sort(d + 1, d + n + 1);
  for (i = 1; i <= n; ++i) {
    if (d[i] == d[i - 1]) {
      sum += prev++;
    } else
      prev = 1;
  }
  cout << sum;
  return 0;
}
