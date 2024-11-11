#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double eps = (1e-9);
int dcmp(double x, double y) { return fabs(x - y) <= eps ? 0 : x < y ? -1 : 1; }
int n, m;
int mem[200000];
int minMoves(int x) {
  if (x == m) return 0;
  int& ret = mem[x];
  if (ret != -1) return ret;
  ret = INT_MAX;
  if (x < m) ret = min(ret, 1 + minMoves(x * 2));
  if (x > 1) ret = min(ret, 1 + minMoves(x - 1));
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  memset(mem, -1, sizeof(mem));
  cin >> n >> m;
  cout << minMoves(n);
  return 0;
}
