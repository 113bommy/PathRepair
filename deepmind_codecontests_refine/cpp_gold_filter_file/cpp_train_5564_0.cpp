#include <bits/stdc++.h>
using namespace std;
int n, m, k, w, nm;
char ls[1000][10][10];
int _d[1000][1000];
int used[1000], res[1000], sz = 0, c = 0;
int main() {
  cin >> n >> m >> k >> w;
  nm = n * m;
  c = nm;
  for (int i = 0; i < k; i++)
    for (int y = 0; y < n; y++)
      for (int x = 0; x < m; x++) cin >> ls[i][y][x];
  for (int a = 0; a < k; a++)
    for (int b = 0; b < k; b++) {
      int res = 0;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (ls[a][i][j] != ls[b][i][j]) res++;
      _d[a][b] = res;
    }
  res[0] = 0;
  used[0] = 1;
  sz = 1;
  stringstream ss;
  ss << "1 0" << endl;
  while (sz < k) {
    int mini = -1, minval = -1, minj = -1, type = 0;
    for (int j = 0; j < sz; j++) {
      for (int i = 0; i < k; i++) {
        if (used[i]) continue;
        int a = _d[res[j]][i] * w, t = min(a, nm);
        if (t < minval || mini < 0) {
          mini = i;
          minval = t;
          minj = -1;
          if (a < nm) {
            minj = res[j];
            type = 1;
          }
        }
      }
    }
    res[sz++] = mini;
    used[mini] = 1;
    ss << mini + 1 << " " << minj + 1 << endl;
    c += minval;
  }
  cout << c << endl << ss.str();
  return 0;
}
