#include <bits/stdc++.h>
using namespace std;
int p[10][100][3];
pair<int, int> o[100];
int n, m, k, mog;
void ou() { cout << mog << endl; }
void ot(int a, int b) {
  int i, pb, pm;
  pb = k;
  pm = 0;
  for (i = 0; i < m; i++) {
    o[i].first = p[b][i][1] - p[a][i][0];
    o[i].second = p[a][i][2];
  }
  sort(o, o + m);
  for (i = m - 1; i >= 0; i--)
    if (pb > 0) {
      pm += max(min(pb, o[i].second) * o[i].first, 0);
      pb -= o[i].second;
    }
  mog = max(mog, pm);
}
void tst(int t) {
  int i;
  for (i = t - 1; i >= 0; i--) {
    ot(t, i);
    ot(i, t);
  }
}
void inp() {
  mog = 0;
  cin >> n >> m >> k;
  int i, j, q;
  string str;
  for (i = 0; i < n; i++) {
    cin >> str;
    for (j = 0; j < m; j++)
      for (q = 0; q < 3; q++) cin >> p[i][j][q];
    tst(i);
  }
  ou();
}
int main() { inp(); }
