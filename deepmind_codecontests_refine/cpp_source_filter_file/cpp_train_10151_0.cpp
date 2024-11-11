#include <bits/stdc++.h>
using namespace std;
const int INF = 100;
long long t, a, b;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long inf = 10 * 1000 * 1000 * 1000ull * 1000 * 1000 * 1000ull;
bool check(long long a, long long b) {
  uint64_t q = inf / a;
  return b <= q;
}
long long lcm(long long a, long long b) {
  long long g = gcd(a, b);
  a /= g;
  if (check(a, b))
    return a * b;
  else
    return inf;
}
long long solve(long long a, long long b, long long t) {
  if (a == b) return t;
  if (t < a && t < b) return t;
  long long ans = 0;
  long long c = lcm(a, b);
  long long cnt = t / c - 1;
  long long left = t - (cnt + 1) * c + 1;
  ans += cnt * min(a, b);
  ans += min(a - 1, min(b - 1, t));
  ans += min(a, min(b, left));
  return ans;
}
int main() {
  cin >> t >> a >> b;
  long long res = solve(a, b, t);
  long long g = gcd(res, t);
  cout << res / g << "/" << t / g;
}
