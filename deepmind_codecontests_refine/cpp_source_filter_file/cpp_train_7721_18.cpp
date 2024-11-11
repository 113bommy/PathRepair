#include <bits/stdc++.h>
using namespace std;
int cntp[1000][5], n, m, points[5];
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    for (int j = 0; j < m; ++j) ++cntp[j][s[j] - 'A'];
  }
  for (int i = 0; i < m; ++i) scanf("%d", &points[i]);
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int maxp = 0;
    for (int j = 0; j < 5; ++j) maxp = max(maxp, cntp[i][j]);
    ans += maxp * points[i];
  }
  printf("%d", ans);
}
