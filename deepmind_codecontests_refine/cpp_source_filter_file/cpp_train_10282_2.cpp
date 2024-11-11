#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
long long ex_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = ex_gcd(b, a % b, y, x);
  y = y - a / b * x;
  return d;
}
long long linearmod(long long a, long long b, long long c) {
  long long x, y;
  long long d = ex_gcd(a, c, x, y);
  if (b % d) return -1;
  x = b / d * x;
  long long m = c / d;
  x = (x % m + m) % m;
  return x == 0 ? m : x;
}
int n, m, x, y, vx, vy;
pair<int, int> hole[5];
void rturn() {
  int tmp = x;
  x = y;
  y = n - tmp;
  tmp = vy;
  vy = -vx;
  vx = tmp;
  swap(n, m);
  hole[4] = hole[0];
  for (int i = 0; i < 4; i++) hole[i] = hole[i + 1];
}
int main() {
  cin >> n >> m >> x >> y >> vx >> vy;
  hole[0] = {0, 0};
  hole[1] = {n, 0};
  hole[2] = {n, m};
  hole[3] = {0, m};
  if (min(abs(vx), abs(vy)) == 0) {
    if (vx) rturn();
    pair<int, int> ans;
    if (x == 0)
      ans = (vy == 1) ? hole[3] : hole[0];
    else if (x == n)
      ans = (vy == 1) ? hole[1] : hole[2];
    else
      puts("-1"), exit(0);
    printf("%d %d\n", ans.first, ans.second);
  } else {
    int cnt;
    if (vx < 0)
      cnt = (vy < 0) ? 2 : 1;
    else
      cnt = (vy < 0) ? 3 : 0;
    while (cnt--) rturn();
    int vert = 0, hori = 0;
    int b0 = y - x;
    if (b0 < 0) vert += abs(b0) / m - (b0 % m == 0) + 1, b0 = (b0 % m + m) % m;
    long long k = linearmod(n % m, m - b0, m);
    if (k == -1) puts("-1"), exit(0);
    hori = (k + 1) % 2;
    vert += (1ll * b0 + k * n) / m - 1;
    vert %= 2;
    if (hori) swap(hole[0], hole[1]), swap(hole[3], hole[2]);
    if (vert) swap(hole[3], hole[0]), swap(hole[2], hole[1]);
    printf("%d %d\n", hole[2].first, hole[2].second);
  }
}
