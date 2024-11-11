#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e4 * 3 + 3;
const int mmax = 20;
const long double pi = M_PI;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
int n, m, k, a[nmax][mmax], ans[nmax], s[nmax], x, y;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    x--;
    y--;
    ans[x]--;
    s[y]++;
  }
  for (int i = 0; i < n; i++) {
    long long ss = ans[i];
    for (int j = 0; j < m; j++) ss += s[j] * a[i][j];
    cout << ss << " ";
  }
}
