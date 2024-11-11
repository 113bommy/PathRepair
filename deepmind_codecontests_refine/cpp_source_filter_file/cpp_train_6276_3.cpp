#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535;
long long powi(long long base, int p) {
  long long res = 1;
  while (p--) res *= base;
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
bool is_vowel(char c) {
  c = tolower(c);
  return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'y';
}
int res[4000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int xa, ya, xb, yb, n;
  cin >> xa >> ya >> xb >> yb >> n;
  vector<pair<int, int>> points;
  int tx = min(xa, xb), ty = max(ya, yb), bx = max(xa, xb), by = min(ya, yb);
  for (int i = tx; i <= bx; i++) points.push_back({i, ty});
  for (int i = ty - 1; i > by; i--) points.push_back({bx, i});
  for (int i = bx; i >= tx; i--) points.push_back({i, by});
  for (int i = by + 1; i < ty; i++) points.push_back({tx, i});
  for (int i = 0; i < n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    for (int j = 0; j < points.size(); j++) {
      int dx = points[j].first - x, dy = points[j].second - y;
      if (res[j] || abs(dx) > r || abs(dy) > r) continue;
      if (sqrt(dx * dx + dy * dy) <= r) res[j] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < points.size(); i++) ans += res[i] == 0;
  cout << ans;
  return 0;
}
