#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
unsigned long long cover[500][500][8];
pair<int, int> a[500], b[500];
bool check(const pair<int, int>& a, const pair<int, int>& b,
           const pair<int, int>& c, const pair<int, int>& d) {
  long long ax = a.first - b.first, ay = a.second - b.second;
  long long bx = c.first - d.first, by = c.second - d.second;
  return ax * by > ay * bx;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  for (int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
  sort(a, a + n);
  sort(b, b + m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (check(a[i], a[j], b[k], a[j])) {
          cover[i][j][k >> 6] |= 1ull << (k & 63);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      for (int k = 0; k < j; k++) {
        if (check(a[i], a[j], a[k], a[j]))
          ans += !(cover[i][j][0] & cover[j][k][0] & cover[k][i][0] |
                   cover[i][j][1] & cover[j][k][1] & cover[k][i][1] |
                   cover[i][j][2] & cover[j][k][2] & cover[k][i][2] |
                   cover[i][j][3] & cover[j][k][3] & cover[k][i][3] |
                   cover[i][j][4] & cover[j][k][4] & cover[k][i][4] |
                   cover[i][j][5] & cover[j][k][5] & cover[k][i][5] |
                   cover[i][j][6] & cover[j][k][6] & cover[k][i][6] |
                   cover[i][j][7] & cover[j][k][7] & cover[k][i][7]);
        else
          ans += !(cover[j][i][0] & cover[k][j][0] & cover[i][k][0] |
                   cover[j][i][1] & cover[k][j][1] & cover[i][k][1] |
                   cover[j][i][2] & cover[k][j][2] & cover[i][k][2] |
                   cover[j][i][3] & cover[k][j][3] & cover[i][k][3] |
                   cover[j][i][4] & cover[k][j][4] & cover[i][k][4] |
                   cover[j][i][5] & cover[k][j][5] & cover[i][k][5] |
                   cover[j][i][6] & cover[k][j][6] & cover[i][k][6] |
                   cover[j][i][7] & cover[k][j][7] & cover[i][k][7]);
      }
  cout << ans << endl;
}
