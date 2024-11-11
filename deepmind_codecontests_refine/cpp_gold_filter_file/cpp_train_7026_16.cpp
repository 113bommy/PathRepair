#include <bits/stdc++.h>
using namespace std;
const int NMAX = 4e3 + 10, inf = 0x3f3f3f3f;
int N, M;
int min1[NMAX], min2[NMAX];
int mat[NMAX][NMAX];
vector<int> L[NMAX];
int main() {
  ios_base::sync_with_stdio(false);
  int i, j, k;
  cin >> N >> M;
  memset(min1, inf, sizeof(min1));
  memset(min2, inf, sizeof(min2));
  for (i = 1; i <= M; ++i) {
    int x, y;
    cin >> x >> y;
    L[x].push_back(y);
    L[y].push_back(x);
    mat[x][y] = mat[y][x] = 1;
  }
  int res = inf;
  for (i = 1; i <= N; ++i) {
    for (j = 0; j < L[i].size(); ++j) {
      for (k = 0; k < L[i].size(); ++k) {
        if (mat[L[i][j]][L[i][k]]) {
          res = min(res, int(L[i].size() + L[L[i][j]].size() +
                             L[L[i][k]].size() - 6));
        }
      }
    }
  }
  if (res >= inf)
    cout << "-1\n";
  else
    cout << res << '\n';
  return 0;
}
