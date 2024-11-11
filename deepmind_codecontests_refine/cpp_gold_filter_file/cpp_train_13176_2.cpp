#include <bits/stdc++.h>
using namespace std;
long long l, r, m, k, ans, p = 2, d, x, t, lc, rc, la, ra, lt, rt;
long long n, i, z;
string a[111111], b[111111];
map<string, long long> us;
pair<long long, string> a1[111111], b1[111111];
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    us[a[i]]++;
  }
  for (i = 1; i <= m; i++) {
    cin >> b[i];
    us[b[i]]++;
  }
  for (i = 1; i <= n; i++) {
    a1[i].first = us[a[i]];
    a1[i].second = a[i];
  }
  for (i = 1; i <= m; i++) {
    b1[i].first = us[b[i]];
    b1[i].second = b[i];
  }
  sort(a1 + 1, a1 + 1 + n);
  sort(b1 + 1, b1 + 1 + m);
  while (x == 0) {
    if (n == 0) {
      cout << "NO";
      return 0;
    }
    while (us[a1[n].second] == 0) {
      if (n == 0) {
        cout << "NO";
        return 0;
      }
      n--;
    }
    us[a1[n].second] = 0;
    n--;
    if (m == 0) {
      cout << "YES";
      return 0;
    }
    while (us[b1[m].second] == 0) {
      if (m == 0) {
        cout << "YES";
        return 0;
      }
      m--;
    }
    us[b1[m].second] = 0;
    m--;
  }
}
