#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> x(m), y(m), d(a + b);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    y[i] += a;
    d[--x[i]]++, d[--y[i]]++;
  }
  int C = *max_element(d.begin(), d.end());
  vector<vector<int> > c(a + b, vector<int>(C, -1));
  for (int i = 0; i < m; i++) {
    int c1 = -1, c2 = -1;
    for (int j = 0; j < C; j++) {
      if (c[x[i]][j] == -1) c1 = j;
      if (c[y[i]][j] == -1) c2 = j;
      if (c1 != -1 && c1 == c2) break;
    }
    if (c1 != c2) {
      vector<int> vr{y[i]};
      for (int j = y[i], col = c1;; j = vr.back(), col = (c1 ^ c2 ^ col)) {
        if (c[j][col] == -1) break;
        vr.push_back(c[j][col]);
        c[vr.back()][col] = -1, c[vr[vr.size() - 2]][col] = -1;
      }
      for (int j = 0, nwcol = c2; j + 1 < vr.size();
           j++, nwcol = (c1 ^ c2 ^ nwcol)) {
        c[vr[j]][nwcol] = vr[j + 1], c[vr[j + 1]][nwcol] = vr[j];
      }
    }
    c[x[i]][c1] = y[i];
    c[y[i]][c1] = x[i];
  }
  cout << C << "\n";
  for (int i = 0; i < m; i++) {
    int w = find(c[x[i]].begin(), c[x[i]].end(), y[i]) - c[x[i]].begin();
    cout << w + 1 << " ";
  }
  cout << "\n";
  return 0;
}
