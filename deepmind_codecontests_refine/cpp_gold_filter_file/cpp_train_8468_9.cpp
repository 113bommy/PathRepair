#include <bits/stdc++.h>
using namespace std;
const double math_pi = 2 * acos(0.);
int main() {
  int n, m, k, x, y, z;
  cin >> n >> m >> k;
  vector<vector<int> > a;
  for (int t = 0; t < n; t++) a.push_back(vector<int>(m));
  for (int t = 0; t < n; t++)
    for (int i = 0; i < m; i++) cin >> a[t][i];
  char s;
  map<int, int> c, r;
  for (int t = 0; t < n; t++) r[t] = t;
  for (int i = 0; i < m; i++) c[i] = i;
  while (k--) {
    cin >> s >> x >> y;
    x--, y--;
    if (s == 'c') z = c[x], c[x] = c[y], c[y] = z;
    if (s == 'r') z = r[x], r[x] = r[y], r[y] = z;
    if (s == 'g') cout << a[r[x]][c[y]] << endl;
  }
  return 0;
}
