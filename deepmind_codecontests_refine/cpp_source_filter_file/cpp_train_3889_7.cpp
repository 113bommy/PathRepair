#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long c[n][m];
  int tmp;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      scanf("%d", &tmp);
      c[i][j] = tmp;
    }
  long long ox = 0, oy = 0;
  long long v1, v2, v3, v4;
  v1 = v2 = v3 = v4 = 0;
  for (long long i = 0, cy = -2; i < n; ++i, cy -= 4) {
    for (long long j = 0, cx = -2; j < m; ++j, cx -= 4) {
      v1 += c[i][j] * (((cx - ox) * (cx - ox)) + ((cy - oy) * (cy - oy)));
      v2 += c[i][j] * (ox - cx);
      v3 += c[i][j] * (oy - cy);
      v4 += c[i][j];
    }
  }
  long long mini = v1;
  int ir, jr;
  for (int i = 0, y = 0; i <= n; ++i, y -= 4) {
    for (int j = 0, x = 0; j <= m; ++j, x -= 4) {
      long long q =
          v1 + 2 * x * v2 + 2 * y * v3 + (((x) * (x)) + ((y) * (y))) * v4;
      if (q < mini) {
        mini = q;
        ir = i, jr = j;
      }
    }
  }
  cout << mini << endl;
  cout << ir << " " << jr << endl;
  return 0;
}
