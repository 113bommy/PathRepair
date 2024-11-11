#include <bits/stdc++.h>
using namespace std;
int i, j, x, y, n, m, p[502], a[502], ans;
int P(int u) {
  if (p[u] == u) return u;
  p[u] = P(p[u]);
  return p[u];
}
void uni(int x, int y) { p[P(x)] = P(y); }
int main() {
  cin >> n >> m;
  if (m > n) {
    cout << "NO";
    return 0;
  }
  for (i = 1; i <= n; i++) p[i] = i;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    a[x]++;
    a[y]++;
    if (P(x) == P(y) && i != n) {
      cout << "NO";
      return 0;
    }
    uni(x, y);
  }
  for (i = 1; i <= n; i++)
    if (a[i] > 2) {
      cout << "NO";
      return 0;
    }
  cout << "YES" << endl;
  cout << n - m << endl;
  for (i = 1; i <= n; i++)
    while (a[i] < 2) {
      ans = i + (n != 1);
      for (j = ans; j <= n; j++)
        if (a[j] < 2 && (n <= 2 || m + 1 == n || P(i) != P(j))) {
          cout << i << " " << j << endl;
          m++;
          a[i]++;
          a[j]++;
          uni(i, j);
          break;
        }
    }
}
