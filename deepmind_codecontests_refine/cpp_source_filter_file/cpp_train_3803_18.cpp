#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int MAXN = 100100;
string st;
int n, m, q;
int mat[100][100];
struct quer {
  int t;
  int r, c, x;
};
quer que[MAXN];
inline void moveRow(int x) {
  for (int i = m - 1; i > 0; --i) {
    swap(mat[x][i], mat[x][i - 1]);
  }
}
inline void moveColumn(int x) {
  for (int i = n - 1; i > 0; --i) {
    swap(mat[i][x], mat[i - 1][x]);
  }
}
void solve() {
  cin >> n >> m >> q;
  for (int i = 0; i < q; ++i) {
    cin >> que[i].t;
    if (que[i].t == 3)
      cin >> que[i].r >> que[i].c >> que[i].x;
    else
      cin >> que[i].r;
  }
  for (int i = q - 1; i >= 0; --i) {
    if (que[i].t == 1) {
      moveRow(que[i].r - 1);
    }
    if (que[i].t == 2) {
      moveColumn(que[i].t - 1);
    }
    if (que[i].t == 3) {
      mat[que[i].r - 1][que[i].c - 1] = que[i].x;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << mat[i][j] << ' ';
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(1313);
  solve();
  return 0;
}
