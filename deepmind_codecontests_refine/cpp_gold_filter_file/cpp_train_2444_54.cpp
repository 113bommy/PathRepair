#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
bool v[1000][1000];
int n, m, k, z, w, t;
bool h = false;
void f(int x, int y, int x1, int y1, char need) {
  if ((a[x][y] != need) || x < 0 || x >= n || y < 0 || y >= m) return;
  if (v[x][y]) {
    h = true;
    return;
  }
  v[x][y] = true;
  if (!(x + 1 == x1 && y == y1)) f(x + 1, y, x, y, need);
  if (!(x == x1 && y + 1 == y1)) f(x, y + 1, x, y, need);
  if (!(x - 1 == x1 && y == y1)) f(x - 1, y, x, y, need);
  if (!(x == x1 && y - 1 == y1)) f(x, y - 1, x, y, need);
}
void intia() {
  t = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) v[i][j] = false;
}
int main() {
  cin >> n >> m;
  intia();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!v[i][j]) {
        f(i, j, i, j, a[i][j]);
      }
    }
  }
  if (h)
    cout << "Yes";
  else
    cout << "No";
}
