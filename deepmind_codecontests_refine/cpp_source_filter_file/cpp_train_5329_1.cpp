#include <bits/stdc++.h>
using namespace std;
const int base = 131;
const int MOD = 1e9 + 7;
const long long MM = 1ll * MOD * MOD;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
void AddMOD(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int Gcd(int x, int y) {
  if (y == 0) return x;
  return Gcd(y, x % y);
}
template <class T>
inline void Gmax(T &x, T y) {
  x = max((x), (y));
}
template <class T>
inline void Gmin(T &x, T y) {
  x = min((x), (y));
}
const int maxn = 2e5 + 5;
bool comp(int a, int b) { return a > b; }
void Solve() {
  int n, p[maxn];
  int x, y, a, b;
  long long k;
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> p[i], p[i] /= 100;
  cin >> x >> a >> y >> b >> k;
  if (x < y) {
    swap(x, y);
    swap(a, b);
  }
  sort(p + 1, p + 1 + n, comp);
  int l = 0, r = n + 1;
  long long c = a * b / Gcd(a, b);
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    int sl1 = mid / a;
    int sl2 = mid / b;
    int sl3 = mid / c;
    long long pr = 0;
    sl2 -= sl3;
    sl1 -= sl3;
    for (int i = 1; i <= sl3; i++) pr += p[i] * (x + y);
    for (int i = 1; i <= sl1; i++) pr += p[sl3 + i] * x;
    for (int i = 1; i <= sl2; i++) pr += p[sl3 + sl1 + i] * y;
    if (pr < k)
      l = mid;
    else
      r = mid;
  }
  if (r == n + 1)
    cout << -1 << "\n";
  else
    cout << r << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int test = 1;
  cin >> test;
  while (test--) Solve();
  return 0;
}
