#include <bits/stdc++.h>
using namespace std;
long long dx4[4] = {0, 1, 0, -1};
long long dy4[4] = {1, 0, -1, 0};
long long dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
long long dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
double calcDistance(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
long long power(long long b, long long p, long long m) {
  if (p == 0) return 1;
  long long t = power(b, p / 2, m);
  t = (t * t) % m;
  if (p % 2 == 1) t = (t * b) % m;
  return t;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long dp[n + 1];
  dp[1] = 2 % m;
  long long x = power(3, n - 1, m);
  long long ans = (2 * x + x - 1 + m) % m;
  cout << ans;
  return 0;
}
