#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m;
bool vis[N][N];
double f[N][N];
double F(int x, int y) {
  if (!y) return 1;
  if (!x) return 1 / (y + 1.0);
  if (vis[x][y]) return f[x][y];
  vis[x][y] = 1;
  double a = 1 - F(y, x - 1);
  double b = (1 + y * (1 - F(y - 1, x))) / (y + 1.0);
  double c = b - 1 / (y + 1.0);
  double p = (c - b) / (a - b + c - 1);
  double q = (c - 1) / (a - b + c - 1);
  return f[x][y] = max(1 / (y + 1.0),
                       p * q * (a - b + c - 1) + p + q * b + c - q * c - p * c);
}
int main() {
  int n, m;
  cin >> n >> m;
  printf("%.12f %.12f\n", F(n, m), 1 - F(n, m));
  return 0;
}
