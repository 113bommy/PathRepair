#include <bits/stdc++.h>
using namespace std;
long long dx4[4] = {0, 1, 0, -1};
long long dy4[4] = {1, 0, -1, 0};
long long dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
long long dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
double calcDistance(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
long long power(long long b, long long p) {
  if (p == 0) return 1;
  long long t = power(b, p / 2);
  t = t * t;
  if (p % 2 == 1) t = t * b;
  return t;
}
long long C[1000][1000] = {};
void fact() {
  for (long long i = 1; i <= 30; i++) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; j++) {
      C[i][j] = (C[i][j - 1] * (i - j + 1)) / j;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact();
  long long n, m, t;
  cin >> n >> m >> t;
  long long ans = 0;
  for (long long i = 4; i < t; i++) {
    long long x = i, y = t - x;
    ans += C[n][x] * C[m][y];
  }
  cout << ans;
  return 0;
}
