#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<string> table(n);
  vector<pair<int, int> > p;
  for (int i = 0; i < n; ++i) cin >> table[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (table[i][j] == '*') p.push_back({i + 1, j + 1});
    }
  }
  int x = 0, y = 0;
  if (p[0].first == p[1].first)
    x = p[2].first;
  else if (p[1].first == p[2].first)
    x = p[0].first;
  else if (p[0].first == p[2].first)
    x = p[1].first;
  if (p[0].second == p[1].second)
    y = p[2].second;
  else if (p[1].second == p[2].second)
    y = p[0].second;
  else if (p[0].second == p[2].second)
    y = p[1].second;
  cout << x << " " << y << endl;
  return 0;
}
