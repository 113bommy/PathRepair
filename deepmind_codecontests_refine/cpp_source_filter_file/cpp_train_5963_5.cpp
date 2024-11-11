#include <bits/stdc++.h>
using namespace std;
int a[333][333], b[333][333], p[333], res[333], c[333], n;
set<pair<int, int> > s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      a[i][j]--;
      b[i][a[i][j]] = 1000 - j;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  memset(res, -1, sizeof(res));
  memset(c, -1, sizeof(c));
  for (int i = 0; i < n; i++) {
    int pos = -1;
    for (int j = 0; j < n; j++)
      if (p[i] == i) pos = j;
    s.insert(pair<int, int>(pos, i));
    pair<int, int> x = *s.begin();
    for (int j = 0; j < n; j++) {
      if (x.second != j) {
        if (b[j][x.second] > c[j]) {
          c[j] = b[j][x.second];
          res[j] = i;
        }
      }
      if (x.second == j) {
        if (s.size() > 1) {
          pair<int, int> y = *(++s.begin());
          if (b[j][y.second] > c[j]) {
            c[j] = b[j][y.second];
            res[j] = i;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", res[i] + 1);
  }
  puts("");
  return 0;
}
