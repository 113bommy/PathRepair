#include <bits/stdc++.h>
using namespace std;
enum { North, East, South, West };
int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};
class node {
 public:
  int o, x, y, v;
  node(){};
  node(int _o, int _x, int _y, int _v) { o = _o, x = _x, y = _y, v = _v; }
};
const int MN = 135;
stack<node> data;
int n, m, q;
int mat[MN][MN];
void row(int p) {
  int x = mat[p][n - 1];
  for (int i = n - 1; i > 0; i--) {
    mat[p][i] = mat[p][i - 1];
  }
  mat[p][0] = x;
}
void col(int p) {
  int x = mat[n - 1][p];
  for (int i = m - 1; i > 0; i--) {
    mat[i][p] = mat[i - 1][p];
  }
  mat[0][p] = x;
}
void init() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cout << "[FREOPEN]" << endl;
  return;
}
int main() {
  memset(mat, 0, sizeof(mat));
  scanf("%d %d %d", &n, &m, &q);
  while (q--) {
    int o;
    scanf("%d", &o);
    if (o == 1) {
      int x;
      scanf("%d", &x);
      x--;
      data.push(node(o, x, -1, -1));
    } else if (o == 2) {
      int x;
      scanf("%d", &x);
      x--;
      data.push(node(o, x, -1, -1));
    } else {
      int x, y, v;
      scanf("%d %d %d", &x, &y, &v);
      x--, y--;
      data.push(node(o, x, y, v));
    }
  }
  while (!data.empty()) {
    int o = data.top().o;
    if (o == 1) {
      int x = data.top().x;
      row(x);
    } else if (o == 2) {
      int x = data.top().x;
      col(x);
    } else {
      int x = data.top().x;
      int y = data.top().y;
      int v = data.top().v;
      mat[x][y] = v;
    }
    data.pop();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      j > 0 ? printf(" ") : NULL;
      printf("%d", mat[i][j]);
    }
    printf("\n");
  }
  return 0;
}
