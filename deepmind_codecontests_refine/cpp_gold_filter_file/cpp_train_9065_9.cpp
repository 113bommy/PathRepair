#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
bool c[1000][1000];
int main() {
  int n, m;
  vector<int> y, x, _count;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == '*') {
        int up = 0, down = 0, left = 0, right = 0, res;
        for (int k = i - 1; k >= 0 && a[k][j] == '*'; k--) up++;
        for (int k = i + 1; k < n && a[k][j] == '*'; k++) down++;
        for (int k = j - 1; k >= 0 && a[i][k] == '*'; k--) left++;
        for (int k = j + 1; k < m && a[i][k] == '*'; k++) right++;
        res = min(min(up, down), min(left, right));
        if (res > 0) {
          y.push_back(i);
          x.push_back(j);
          _count.push_back(res);
          c[i][j] = true;
          for (int k = i - 1; k >= i - res; k--) c[k][j] = true;
          for (int k = i + 1; k <= i + res; k++) c[k][j] = true;
          for (int k = j - 1; k >= j - res; k--) c[i][k] = true;
          for (int k = j + 1; k <= j + res; k++) c[i][k] = true;
        }
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == '*' && !c[i][j]) {
        cout << -1;
        return 0;
      }
  cout << y.size() << '\n';
  for (int i = 0; i < y.size(); i++)
    cout << y[i] + 1 << ' ' << x[i] + 1 << ' ' << _count[i] << '\n';
  return 0;
}
