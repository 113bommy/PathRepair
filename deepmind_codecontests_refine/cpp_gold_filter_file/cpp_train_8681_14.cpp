#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  char a[n][n], r[n], c[n];
  memset(r, 0, sizeof(r));
  memset(c, 0, sizeof(c));
  for (auto i = 0; i != n; i++)
    for (auto j = 0; j != n; j++) {
      cin >> a[i][j];
      if (a[i][j] == '.') {
        r[i] = 1;
        c[j] = 1;
      }
    }
  for (auto i = 0; i != n; i++)
    for (auto j = 0; j != n; j++)
      if (a[i][j] == 'E' && !r[i] && !c[j]) {
        cout << -1 << "\n";
        return 0;
      }
  vector<pair<long long int, long long int>> row, col;
  for (auto i = 0; i != n; i++) {
    for (auto j = 0; j != n; j++) {
      if (a[i][j] == '.') {
        row.push_back(make_pair((i + 1), (j + 1)));
        break;
      }
    }
    for (auto j = 0; j != n; j++) {
      if (a[j][i] == '.') {
        col.push_back(make_pair((j + 1), (i + 1)));
        break;
      }
    }
  }
  if ((long long int)(row).size() == n)
    for (auto i = 0; i != n; i++)
      cout << row[i].first << " " << row[i].second << "\n";
  else
    for (auto i = 0; i != n; i++)
      cout << col[i].first << " " << col[i].second << "\n";
  return 0;
}
