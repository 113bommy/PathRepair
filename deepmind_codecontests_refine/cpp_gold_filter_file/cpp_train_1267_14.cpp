#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dir[8][2] = {{-1, 0},  {1, 0}, {0, -1}, {0, 1},
                 {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
const int MAXN = 2e5 + 5;
const int INF = 1 << 30;
const long long mod = 1e9 + 7;
const double eps = 1e-8;
const long long inff = 0x3f3f3f3f3f3f3f3f;
int n, a[MAXN], x, y, l, r;
int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    l = max(1, i - x);
    r = min(n, i + y);
    int fl = 0;
    for (int j = l; j <= r; ++j) {
      if (a[j] < a[i]) {
        fl = 1;
      }
    }
    if (!fl) {
      cout << i << endl;
      return 0;
    }
  }
}
