#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const long long INF = 1LL * inf * inf;
const double eps = 1e-9;
const int MAXN = 2500;
const int md = (int)1e9 + 7;
int n, m, t, a[200][200];
vector<pair<int, int> > q;
void swift_row(int x, int d) {
  int b[200];
  for (int i = 0; i < m; i++) b[(i + d + m) % m] = a[x][i];
  for (int i = 0; i < m; i++) a[x][i] = b[i];
}
void swift_col(int x, int d) {
  int b[200];
  for (int i = 0; i < n; i++) b[(i + d + n) % n] = a[i][x];
  for (int i = 0; i < n; i++) a[i][x] = b[i];
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 0; i < t; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int x;
      scanf("%d", &x);
      x--;
      q.push_back(make_pair(1, x));
      swift_row(x, -1);
    }
    if (type == 2) {
      int x;
      scanf("%d", &x);
      x--;
      q.push_back(make_pair(2, x));
      swift_col(x, -1);
    }
    if (type == 3) {
      int x, y, d;
      scanf("%d%d%d", &x, &y, &d);
      a[x - 1][y - 1] = d;
    }
  }
  reverse(q.begin(), q.end());
  for (int i = 0; i < q.size(); i++) {
    if (q[i].first == 1)
      swift_row(q[i].second, 1);
    else
      swift_col(q[i].second, 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
