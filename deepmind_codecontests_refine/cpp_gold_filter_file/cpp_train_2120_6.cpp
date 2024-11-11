#include <bits/stdc++.h>
using namespace std;
stringstream ss;
int na, ma, nb, mb;
int a[51][51], b[51][51];
int f(int x, int y) {
  int ret = 0;
  for (int i = 1; i <= na; i++)
    if (1 <= x + i && x + i <= nb)
      for (int j = 1; j <= ma; j++)
        if (1 <= y + j && y + j <= mb) ret += a[i][j] * b[x + i][y + j];
  return ret;
}
int main() {
  cin >> na >> ma;
  char tmp;
  for (int i = 1; i <= na; i++) {
    for (int j = 1; j <= ma; j++) {
      cin >> tmp;
      a[i][j] = tmp - '0';
    }
  }
  cin >> nb >> mb;
  for (int i = 1; i <= nb; i++) {
    for (int j = 1; j <= mb; j++) {
      cin >> tmp;
      b[i][j] = tmp - '0';
    }
  }
  int mx = 0, r;
  pair<int, int> res = pair<int, int>(0, 0);
  for (int i = -50; i <= 50; i++)
    for (int j = -50; j <= 50; j++)
      if ((r = f(i, j)) >= mx) {
        res = pair<int, int>(i, j);
        mx = r;
      }
  cout << res.first << " " << res.second << endl;
  return 0;
}
