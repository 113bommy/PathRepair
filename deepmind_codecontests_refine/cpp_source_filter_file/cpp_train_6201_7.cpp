#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 100007;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;
int g, inv;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long solve(int b1, int c1, int b2, int c2) {
  long long b = ((b2 - b1) % c2 + c2) % c2;
  if (b % g != 0) return 1LL * INF * INF;
  b /= g;
  long long k = inv * b % (c2 / g);
  return k * c1 + b1;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  g = gcd(2 * n, 2 * m);
  for (int i = (0); i < (2 * n); i++) {
    if (2LL * n / g * i % (2 * m / g) == 1) {
      inv = i;
      break;
    }
  }
  for (int i = (0); i < (k); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    long long res = 1LL * INF * INF;
    res = min(res, solve(x, 2 * n, y, 2 * m));
    res = min(res, solve(2 * n - x, 2 * n, y, 2 * m));
    res = min(res, solve(x, 2 * n, 2 * m - y, 2 * m));
    res = min(res, solve(2 * n - x, 2 * n, 2 * m - y, 2 * m));
    if (res == 1LL * INF * INF) res = -1;
    cout << res << endl;
  }
  return 0;
}
