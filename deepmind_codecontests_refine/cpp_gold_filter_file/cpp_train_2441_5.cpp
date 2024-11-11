#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool b[310][310] = {0};
vector<pair<int, int> > v[50000];
int main() {
  cin >> n >> m >> k;
  int i = 1, c = 1;
  while (i <= n) {
    int j;
    if (i % 2) {
      j = 1;
      for (; j < m; j += 2, c++)
        v[min(c, k)].push_back({i, j}), v[min(c, k)].push_back({i, j + 1});
      if (i == n && m % 2) v[k].push_back({n, m});
    } else {
      j = m - (m % 2 != 0);
      for (; j > 1; j -= 2, c++)
        v[min(c, k)].push_back({i, j}), v[min(c, k)].push_back({i, j - 1});
    }
    if (m % 2 && i % 2 && i != n)
      v[min(c, k)].push_back({i, j + (i % 2 == 0)}),
          v[min(c++, k)].push_back({i + 1, j + (i % 2 == 0)});
    i++;
  }
  for (int i = 1; i <= k; i++) {
    cout << v[i].size();
    for (int j = 0; j < v[i].size(); j++)
      cout << " " << v[i][j].first << " " << v[i][j].second;
    cout << endl;
  }
  return 0;
}
