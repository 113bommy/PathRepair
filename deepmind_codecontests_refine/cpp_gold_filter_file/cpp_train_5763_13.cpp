#include <bits/stdc++.h>
using namespace std;
int dx[9] = {0, 0, 0, 1, -1, -1 - 1, 1, 1},
    dy[9] = {0, 1, -1, 0, 0, -1, 1, -1, 1};
const int base = 1000000007;
const int maxn = 2002;
int n, m, x2, y2;
long long c[maxn][maxn];
long long sumcx, sumcy, sumc, sumcx2, sumcy2, res, best1, best2;
long long sqr(long long a) { return a * a; }
bool ok(int i, int j) { return (i >= 0 && j >= 0 && i <= m && j <= n); }
long long cost(int i, int j) {
  int first = 4 * i, second = 4 * j;
  return (sumc * sqr(first) - 2 * first * sumcx + sumcx2) + sumc * sqr(second) -
         2 * second * sumcy + sumcy2;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int i, j, k, u, v, first, second;
  pair<long long, long long> p0;
  long long F = base, F1 = base, tmp;
  cin >> m >> n;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      cin >> c[i][j];
      sumcx += c[i][j] * (4 * i - 2);
      sumcx2 += c[i][j] * sqr(4 * i - 2);
      sumcy += c[i][j] * (4 * j - 2);
      sumcy2 += c[i][j] * sqr(4 * j - 2);
      sumc += c[i][j];
    }
  p0.first = 0;
  p0.second = 0;
  F = cost(0, 0);
  for (int t = 1; t <= 2000; t++) {
    i = p0.first;
    j = p0.second;
    for (k = 1; k <= 8; k++) {
      first = p0.first + dx[k];
      second = p0.second + dy[k];
      if (!ok(first, second)) continue;
      F1 = cost(first, second);
      if (F > F1) {
        F = F1;
        i = first;
        j = second;
      } else if (F == F1 && first < i) {
        F = F1;
        i = first;
        j = second;
      } else if (F == F1 && first == i && second < j) {
        F = F1;
        i = first;
        j = second;
      }
    }
    if (pair<long long, long long>(i, j) == p0) break;
    p0 = pair<long long, long long>(i, j);
  }
  cout << F << "\n";
  cout << p0.first << " " << p0.second;
  return 0;
}
