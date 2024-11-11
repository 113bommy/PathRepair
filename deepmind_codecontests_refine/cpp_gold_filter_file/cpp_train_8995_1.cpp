#include <bits/stdc++.h>
using namespace std;
long long n, sx, sy, dx, dy, t, k;
struct Node {
  int r, c;
  long long k[6][6];
  void init(int r, int c) {
    this->r = r;
    this->c = c;
    memset(k, 0, sizeof(k));
  }
} node;
Node operator*(Node a, Node b) {
  Node m;
  m.init(a.r, b.c);
  for (int i = 0; i < a.r; i++)
    for (int j = 0; j < b.c; j++)
      for (int x = 0; x < a.c; x++)
        m.k[i][j] = ((m.k[i][j] + a.k[i][x] * b.k[x][j]) % n + n) % n;
  return m;
}
Node ksm(long long b) {
  Node ans;
  Node a;
  ans.init(6, 1);
  a.init(6, 6);
  ans.k[0][0] = sx - 1;
  ans.k[1][0] = sy - 1;
  ans.k[2][0] = dx;
  ans.k[3][0] = dy;
  ans.k[4][0] = 0;
  ans.k[5][0] = 1;
  a.k[0][0] = 2;
  a.k[1][0] = 1;
  a.k[2][0] = 1;
  a.k[3][0] = 1;
  a.k[4][0] = 0;
  a.k[5][0] = 0;
  a.k[0][1] = 1;
  a.k[1][1] = 2;
  a.k[2][1] = 1;
  a.k[3][1] = 1;
  a.k[4][1] = 0;
  a.k[5][1] = 0;
  a.k[0][2] = 1;
  a.k[1][2] = 0;
  a.k[2][2] = 1;
  a.k[3][2] = 0;
  a.k[4][2] = 0;
  a.k[5][2] = 0;
  a.k[0][3] = 0;
  a.k[1][3] = 1;
  a.k[2][3] = 0;
  a.k[3][3] = 1;
  a.k[4][3] = 0;
  a.k[5][3] = 0;
  a.k[0][4] = 1;
  a.k[1][4] = 1;
  a.k[2][4] = 1;
  a.k[3][4] = 1;
  a.k[4][4] = 1;
  a.k[5][4] = 0;
  a.k[0][5] = 2;
  a.k[1][5] = 2;
  a.k[2][5] = 2;
  a.k[3][5] = 2;
  a.k[4][5] = 1;
  a.k[5][5] = 1;
  while (b) {
    if (b & 1) ans = a * ans;
    a = a * a;
    b = b >> 1;
  }
  return ans;
}
int main() {
  scanf("%lld%lld%lld%lld%lld%lld", &n, &sx, &sy, &dx, &dy, &t);
  Node a = ksm(t);
  printf("%lld %lld\n", a.k[0][0] + 1, a.k[1][0] + 1);
  return 0;
}
