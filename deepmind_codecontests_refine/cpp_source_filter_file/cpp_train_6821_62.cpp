#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int inf = ~0U >> 1;
const int mod = 1e9 + 7;
int b[N][N], n, m, k;
map<int, pair<int, int> > R, C;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0, t, x, c; i < k; ++i) {
    scanf("%d %d %d", &t, &x, &c);
    if (t == 1)
      R[x] = pair<int, int>(c, i);
    else
      C[x] = pair<int, int>(c, i);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (R.count(i) && C.count(j)) {
        if (R[i].second > C[j].second)
          b[i][j] = R[i].first;
        else
          b[i][j] = R[i].first;
      } else if (R.count(i))
        b[i][j] = R[i].first;
      else if (C.count(j))
        b[i][j] = C[j].first;
      else
        b[i][j] = 0;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) printf("%d%c", b[i][j], i == m ? '\n' : ' ');
  return 0;
}
