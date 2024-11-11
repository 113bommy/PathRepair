#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int u, long long int v) {
  if (v == 0)
    return u;
  else
    return gcd(v, u % v);
}
int main() {
  int n, m, i, k;
  cin >> n >> m;
  long long int a[n + 5][m + 5], e[n + 5][m + 5];
  long long int r[n + 5], s[m + 5];
  long long int g = 0;
  long long int maxn = 0;
  for (i = 0; i < n; i++) {
    for (k = 0; k < m; k++) {
      cin >> a[i][k];
      maxn = max(maxn, a[i][k]);
    }
  }
  for (i = 0; i < m; i++) {
    s[i] = a[0][i];
  }
  for (i = 0; i < n; i++) {
    r[i] = a[i][0] - s[0];
  }
  for (i = 0; i < n; i++) {
    for (k = 0; k < m; k++) {
      e[i][k] = abs(r[i] + s[k] - a[i][k]);
      g = gcd(e[i][k], g);
    }
  }
  if (g == 0) g = maxn + 1;
  if (g > maxn) {
    cout << "YES" << '\n';
    cout << g << '\n';
    for (i = 0; i < n; i++) {
      while (r[i] < 0) r[i] += g;
      cout << r[i] << ' ';
    }
    cout << endl;
    for (i = 0; i < m; i++) {
      while (s[i] < 0) s[i] += g;
      cout << s[i] << ' ';
    }
  } else
    cout << "NO";
  return 0;
}
