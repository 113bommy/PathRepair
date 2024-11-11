#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const double eps = 1e-10;
const double pi = acos(-1.0);
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
inline void RI(int& x) {
  x = 0;
  char c = getchar();
  while (!((c >= '0' && c <= '9') || c == '-')) c = getchar();
  bool flag = 1;
  if (c == '-') {
    flag = 0;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (!flag) x = -x;
}
long long x;
struct matrix {
  int n;
  long long maze[0 + 10][0 + 10];
  void init(int n) {
    this->n = n;
    memset(maze, 0, sizeof(maze));
  }
  matrix operator*(const matrix& rhs) {
    matrix ans;
    ans.init(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          ans.maze[i][j] = (ans.maze[i][j] + maze[i][k] * rhs.maze[k][j]) % x;
    return ans;
  }
};
matrix qlow(matrix a, long long n) {
  matrix ans;
  ans.init(a.n);
  for (int i = 0; i < a.n; i++) ans.maze[i][i] = 1;
  while (n) {
    if (n & 1) ans = ans * a;
    a = a * a;
    n >>= 1;
  }
  return ans;
}
int main() {
  long long sx, sy, dx, dy, t;
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &x, &sx, &sy, &dx, &dy, &t);
  matrix ans;
  ans.init(6);
  ans.maze[0][0] = ans.maze[0][1] = ans.maze[1][1] = 1;
  ans.maze[1][2] = ans.maze[1][3] = ans.maze[1][4] = 1;
  ans.maze[1][5] = ans.maze[2][4] = ans.maze[2][5] = ans.maze[2][3] = 1;
  ans.maze[3][2] = ans.maze[3][4] = ans.maze[3][5] = 1;
  ans.maze[4][2] = ans.maze[4][4] = ans.maze[5][3] = ans.maze[5][5] = 1;
  ans.maze[0][2] = ans.maze[0][3] = ans.maze[0][4] = 2;
  ans.maze[2][2] = ans.maze[3][3] = ans.maze[0][5] = 2;
  ans = qlow(ans, t);
  matrix ant;
  ant.init(6);
  ant.maze[0][0] = 1;
  ant.maze[0][2] = sx - 1;
  ant.maze[0][3] = sy - 1;
  ant.maze[0][4] = (dx % x + x) % x;
  ant.maze[0][5] = (dy % x + x) % x;
  ant = ant * ans;
  printf("%I64d %I64d\n", ant.maze[0][2] + 1, ant.maze[0][3] + 1);
  return 0;
}
