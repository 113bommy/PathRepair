#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int maxn = (int)1e6 + 10;
;
struct point {
  long long x, y;
  bool operator<(const point& a) const { return y < a.y; }
  long long operator*(point a) { return pow2(x - a.x) + pow2(y - a.y); }
} num[maxn];
long long n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    long long a;
    cin >> a;
    num[i].x = i;
    num[i].y = num[i - 1].y + a;
  }
  long long ans = ((long long)9e18);
  for (int i = 1; i < n + 1; i++) {
    for (int j = i + 1; j < min(n + 1, i + 1100ll); j++) {
      ans = min(ans, num[i] * num[j]);
    }
  }
  cout << ans;
}
