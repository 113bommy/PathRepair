#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const double PI = acos(-1.);
const double eps = 1e-15;
const int MOD = 1e9 + 7;
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long s = power(x, y / 2);
  s *= s;
  if (y & 1) s *= x;
  return s;
}
long long Ceil(long long x, long long y) { return (x + y - 1) / y; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int n;
long long h;
bool check(long long k, vector<long long>& a) {
  long long hp = h;
  for (int i = 0; i < n; i++) {
    long long damage = min(a[i + 1] - a[i], k);
    hp -= damage;
  }
  return hp <= 0;
}
void solve() {
  cin >> n >> h;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  a.emplace_back(INT64_MAX);
  long long l = 1, r = h;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid, a))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    solve();
  }
}
