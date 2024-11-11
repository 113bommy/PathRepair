#include <bits/stdc++.h>
using namespace std;
struct ret {
  int x, y, s;
  ret(int inX, int inY, int inS) : x(inX), y(inY), s(inS) {}
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> v(n);
  for (int i = 0; i < (n); i++) cin >> v[i];
  vector<string> xx(n, string(m, '.'));
  vector<ret> r;
  bool all = true;
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (m); j++) {
      if (v[i][j] == '*') {
        all = false;
        int x = 1;
        while (i - x >= 0 && i + x < n && j - x >= 0 && j - x < m &&
               v[i - x][j] == '*' && v[i + x][j] == '*' && v[i][j - x] == '*' &&
               v[i][j + x] == '*') {
          xx[i - x][j] = '*';
          xx[i + x][j] = '*';
          xx[i][j - x] = '*';
          xx[i][j + x] = '*';
          xx[i][j] = '*';
          x++;
        }
        if (x > 1) r.push_back(ret(i, j, x - 1));
      }
    }
  }
  if (all) printf("0\n");
  if (xx != v || r.size() == 0)
    printf("-1\n");
  else {
    printf("%d\n", r.size());
    for (int i = 0; i < (r.size()); i++)
      printf("%d %d %d\n", r[i].x + 1, r[i].y + 1, r[i].s);
  }
  return 0;
}
