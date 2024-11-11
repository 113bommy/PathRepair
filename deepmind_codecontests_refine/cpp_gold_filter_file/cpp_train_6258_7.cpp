#include <bits/stdc++.h>
int n;
double a[100005], b[100005], p[100005], S;
long long T;
struct point {
  double x, y;
  friend bool operator<(point t1, point t2) { return t1.y > t2.y; }
} A[100005];
struct Matrix {
  double s[3][3];
  void init() {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) s[i][j] = 0;
  }
  friend Matrix operator*(Matrix a, Matrix b) {
    Matrix c;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        c.s[i][j] = 0;
        for (int k = 0; k < 3; k++) c.s[i][j] += a.s[i][k] * b.s[k][j];
      }
    return c;
  }
} bas[100005], f[40], mat;
struct node {
  int id;
  long long lst;
  Matrix p;
};
std::vector<node> sta;
int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n >> T;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i] >> p[i];
    S = std::max(S, b[i] * p[i]);
    A[i] = {p[i], a[i] * p[i]};
  }
  std::sort(A + 1, A + 1 + n);
  for (int i = 1; i <= n; i++) {
    bas[i].s[1][1] = bas[i].s[2][2] = 1, bas[i].s[0][0] = 1 - A[i].x;
    bas[i].s[0][1] = A[i].x, bas[i].s[0][2] = A[i].y, bas[i].s[1][2] = S;
  }
  mat.s[2][0] = 1;
  sta.push_back({1, T, mat});
  for (int i = 2; i <= n; i++) {
    for (; (bas[i] * sta.back().p).s[0][0] >
           (bas[sta.back().id] * sta.back().p).s[0][0];
         sta.pop_back())
      ;
    if (!sta.back().lst) continue;
    node x = sta.back();
    f[0] = bas[x.id];
    for (int j = 1; j <= 35; j++) f[j] = f[j - 1] * f[j - 1];
    for (int j = 35; ~j; j--)
      if (x.lst - (1ll << j) >= 1)
        if ((bas[i] * f[j] * x.p).s[0][0] <= (bas[x.id] * f[j] * x.p).s[0][0])
          x.p = f[j] * x.p, x.lst -= 1ll << j;
    x.p = f[0] * x.p, x.lst--;
    if (x.lst) x.id = i;
    sta.push_back(x);
  }
  Matrix ans = sta.back().p, x = bas[sta.back().id];
  for (long long res = sta.back().lst; res; res >>= 1, x = x * x)
    if (res & 1) ans = x * ans;
  std::cout << std::fixed << std::setprecision(12) << ans.s[0][0] << "\n";
}
