#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<long, long> > rows;
  vector<pair<long, long> > columns;
  int n, m;
  long a, b, c, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= n; i++) {
    rows.push_back(make_pair(0L, 0L));
  }
  for (int i = 0; i <= m; i++) {
    columns.push_back(make_pair(0L, 0L));
  }
  for (long i = 1; i <= k; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      rows[b] = make_pair(i, c);
    } else {
      columns[b] = make_pair(i, c);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ((rows[i].first > columns[j].second) ? rows[i].second
                                                   : columns[j].second)
           << " ";
    }
    cout << endl;
  }
  return 0;
}
