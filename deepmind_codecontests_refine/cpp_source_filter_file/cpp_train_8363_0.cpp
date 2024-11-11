#include <bits/stdc++.h>
using namespace std;
long long a = 0, b = 0, c = 0, n, s, ansx, ansy, ansz, x, y, z, ans = INT_MAX,
          a0, b0;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long tmp = exgcd(b, a % b, x, y);
  long long t = x;
  x = y;
  y = t - a / b * y;
  return tmp;
}
long long f(long long k) {
  long long xx = x + k * b0, yy = y - k * a0;
  return abs(xx * a - yy * b) + abs(yy * b - z * c);
}
bool cmp(long long k1, long long k2) {
  if (x + k1 * b0 < 0) return false;
  if (x + k1 * b0 > z) return true;
  if (y - k1 * a0 < 0) return true;
  if (y - k1 * a0 > z) return false;
  if (x + k2 * b0 < 0) return false;
  if (x + k2 * b0 > z) return true;
  if (y - k2 * a0 < 0) return true;
  if (y - k2 * a0 > z) return false;
  if (x + k1 * b0 > y - k1 * a0) return true;
  if (x + k2 * b0 > y - k2 * a0) return true;
  return f(k1) <= f(k2);
}
int main() {
  scanf("%d %d", &n, &s);
  for (int i = 1, w; i <= n; i++) {
    scanf("%d", &w);
    if (w == 3) a++;
    if (w == 4) b++;
    if (w == 5) c++;
  }
  for (z = 1; z * c <= s; z++) {
    long long g = exgcd(a, b, x, y);
    if ((s - z * c) % g) continue;
    long long k = (s - z * c) / g;
    x *= k, y *= k;
    a0 = a / g, b0 = b / g;
    long long l = INT_MIN, r = INT_MAX;
    while (l < r) {
      long long lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
      if (cmp(lmid, rmid))
        r = rmid - 1;
      else
        l = lmid + 1;
    }
    long long xx = x + l * b0, yy = y - l * a0;
    if (0 <= xx && xx <= yy && yy <= z) {
      if (ans > f(l)) {
        ans = f(l);
        ansx = xx;
        ansy = yy;
        ansz = z;
        ans = f(l);
      }
    }
  }
  if (ans > 2e9)
    printf("-1\n");
  else
    printf("%d %d %d\n", ansx, ansy, ansz);
}
