#include <bits/stdc++.h>
using namespace std;
int a[224][224] = {0};
int n, m, t, x, y, i = 0, ox, oy;
void abc(int i, int j) {
  if (a[i][j] < 4) return;
  a[i + 1][j] = a[i][j] / 4;
  a[i - 1][j] = a[i][j] / 4;
  a[i][j + 1] = a[i][j] / 4;
  a[i][j - 1] = a[i][j] / 4;
  a[i][j] %= 4;
  abc(i + 1, j);
  abc(i - 1, j);
  abc(i, j + 1);
  abc(i, j - 1);
}
int main() {
  cin >> n >> t;
  ox = oy = 112;
  a[ox][oy] = n;
  abc(ox, oy);
  for (i = 0; i < t; i++) {
    cin >> x >> y;
    if (ox + x > 224 || oy + y > 224 || ox + x < 0 || oy + y < 0)
      cout << 0 << endl;
    else
      cout << a[ox + x][oy + y] << '\n';
  }
  return 0;
}
