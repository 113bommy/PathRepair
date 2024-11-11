#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
const int pN = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
void add(long long &x, long long y) {
  x += y;
  x %= MOD;
}
int u, v, n, m;
void Solve(int x, int y, int z) {
  int row = n, cul = m;
  int nx, ny;
  for (int i = 1; i <= x; i++) {
    nx = v;
    ny = row - u + 1;
    u = nx;
    v = ny;
    swap(row, cul);
  }
  for (int i = 1; i <= y; i++) {
    nx = u;
    ny = cul - v + 1;
    u = nx;
    v = ny;
  }
  for (int i = 1; i <= z; i++) {
    nx = cul - v + 1;
    ny = u;
    u = nx;
    v = ny;
    swap(row, cul);
  }
  cout << u << " " << v << endl;
}
int main() {
  int x, y, z, p;
  cin >> n >> m >> x >> y >> z >> p;
  x %= 4;
  y %= 2;
  z %= 4;
  for (int i = 0; i < p; i++) {
    cin >> u >> v;
    Solve(x, y, z);
  }
  return 0;
}
