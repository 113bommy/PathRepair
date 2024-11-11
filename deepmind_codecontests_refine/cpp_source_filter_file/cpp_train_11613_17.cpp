#include <bits/stdc++.h>
using namespace std;
const int z = 300;
struct cool {
  int x, y, d;
};
vector<cool> a[z];
int n, m, p;
bool comp(cool a, cool b) { return (a.d < b.d); }
int main() {
  cin >> n >> m >> p;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x;
      cool c;
      cin >> x;
      c.x = i;
      c.y = j;
      if (x == 1)
        c.d = i + j;
      else
        c.d = 1e9;
      a[x].push_back(c);
    }
  for (int i = 2; i <= p; i++) {
    sort(a[i - 1].begin(), a[i - 1].end(), comp);
    for (int j = 0; j < a[i].size(); j++)
      for (int l = 0; l < min((int)a[i - 1].size(), n + m); l++)
        a[i][j].d =
            min(a[i][j].d, a[i - 1][j].d + abs(a[i - 1][l].x - a[i][j].x) +
                               abs(a[i - 1][l].y - a[i][j].y));
  }
  cout << a[p][0].d;
  return 0;
}
