#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000 + 7;
const double esp = 1e-13;
struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator-(const PT &p) { return PT(x - p.x, y - p.y); }
  PT operator+(const PT &p) { return PT(x + p.x, y + p.y); }
  PT operator*(double c) { return PT(x * c, y * c); }
  PT operator/(double c) { return PT(x / c, y / c); }
  bool operator==(const PT &p) { return x == p.x && y == p.y; }
  bool operator!=(const PT &p) { return x != p.x || y != p.y; }
};
double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}
long long power(long long a, long long n, long long m) {
  long long ans = 1;
  while (n) {
    if (n % 2) ans = ans * a % m;
    a = a * a % m;
    n /= 2;
  }
  return ans;
}
long long s, x, dp[52][10];
long long solve(int pos, int du) {
  if (pos == 50 && du == 0) return 1;
  long long &ans = dp[pos][du];
  if (ans != -1) return ans;
  ans = 0;
  for (long long i = 0; i <= 1; i++)
    for (long long j = 0; j <= 1; j++)
      if (((i + j + du) % 2 == (s >> (pos - 1) & 1)) &&
          (i ^ j == (x >> (pos - 1))))
        ans += solve(pos + 1, (i + j + du) / 2);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cin >> s >> x;
  memset(dp, -1, sizeof(dp));
  cout << 2 * solve(1, 0) - (s == x) * 2;
}
