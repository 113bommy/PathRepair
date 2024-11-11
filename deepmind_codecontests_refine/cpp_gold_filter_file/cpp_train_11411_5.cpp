#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<short, short>, short> > a;
int sum[101][101][11];
int c;
void create(short g) {
  int ye = 0;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++) {
      pair<short, short> cur = make_pair(i, j);
      int s = 0;
      while (a[ye].first == cur) s += (a[ye++].second + g) % (c + 1);
      sum[i][j][g] =
          s + sum[i - 1][j][g] + sum[i][j - 1][g] - sum[i - 1][j - 1][g];
    }
  return;
}
int main() {
  int n, q;
  cin >> n >> q >> c;
  for (int i = 0; i < n; i++) {
    short first, second, val;
    cin >> first >> second >> val;
    a.push_back(make_pair(make_pair(first, second), val));
  }
  sort(a.begin(), a.end());
  a.push_back(make_pair(make_pair(101, 101), 69));
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i <= c; i++) create(i);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    short lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    short wh = t % (c + 1);
    cout << sum[rx][ry][wh] - sum[rx][ly - 1][wh] - sum[lx - 1][ry][wh] +
                sum[lx - 1][ly - 1][wh]
         << endl;
  }
  return 0;
}
