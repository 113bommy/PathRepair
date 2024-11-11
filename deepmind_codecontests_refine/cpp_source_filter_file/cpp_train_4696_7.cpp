#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
long long MOD = 1000000000;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
long long GCD(long long a, long long b) { return b ? GCD(b, a % b) : a; }
long long LCM(long long a, long long b) {
  if (a == 0 || b == 0) return a + b;
  return a * (b / GCD(a, b));
}
bool OOB(long long x, long long y, long long N, long long M) {
  return 0 > x || x >= N || 0 > y || y >= M;
}
int main() {
  long long a, b, x, y;
  cin >> a >> b >> x >> y;
  long long g = GCD(x, y);
  long long x1 = x / g;
  long long y1 = y / g;
  long long ans1 = a / x1;
  long long ans2 = a / y1;
  long long ans = min(ans1, ans2);
  cout << (ans) << '\n';
  return 0;
}
