#include <bits/stdc++.h>
using namespace std;
char a[55][55];
int n, m, t1, t2, t3, t4;
int c[55], k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
inline bool ok(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }
inline int cnt(int i, int j, char ch) {
  int tot = 0;
  for (int(k) = 0; (k) < (4); ++(k))
    if (ok(i + dx[k], j + dy[k]) && a[i + dx[k]][j + dy[k]] == ch) ++tot;
  return tot;
}
int main() {
  cin >> t1 >> t2 >> t3 >> t4;
  n = max(t2, t4);
  m = t1 + t3;
  for (int(i) = 0; (i) < (n); ++(i))
    for (int(j) = 0; (j) < (m); ++(j))
      if (t2 > t4 && i >= t4 && j >= t1)
        a[i][j] = '.';
      else if (t2 < t4 && i >= t2 && j < t1)
        a[i][j] = '.';
      else
        a[i][j] = '?';
  cin >> k;
  for (int(i) = 0; (i) < (k); ++(i)) cin >> c[i];
  for (int(pos) = 0; (pos) < (k); ++(pos)) {
    int bi = 0, bj = 0, bc = 1000000000;
    for (int(i) = 0; (i) < (n); ++(i))
      for (int(j) = 0; (j) < (m); ++(j))
        if (ok(i, j) && a[i][j] == '?' && cnt(i, j, '?') < bc) {
          bi = i;
          bj = j;
          bc = cnt(i, j, '?');
        }
    a[bi][bj] = 'a' + pos;
    for (int(step) = 0; (step) < (c[pos] - 1); ++(step)) {
      int bi = 0, bj = 0, bc = 1000000000, bn = -1000000000;
      for (int(i) = 0; (i) < (n); ++(i))
        for (int(j) = 0; (j) < (m); ++(j))
          if (ok(i, j) && a[i][j] == '?' && cnt(i, j, 'a' + pos) > 0 &&
              (cnt(i, j, '?') < bc ||
               (cnt(i, j, '?') == bc && cnt(i, j, 'a' + pos) > bn))) {
            bi = i;
            bj = j;
            bc = cnt(i, j, '?');
            bn = cnt(i, j, 'a' + pos);
          }
      if (bc == 1000000000) {
        cout << "NO\n";
        return 0;
      }
      a[bi][bj] = 'a' + pos;
    }
  }
  cout << "YES\n";
  for (int(i) = 0; (i) < (n); ++(i)) {
    for (int(j) = 0; (j) < (m); ++(j)) cout << a[i][j];
    cout << endl;
  }
}
