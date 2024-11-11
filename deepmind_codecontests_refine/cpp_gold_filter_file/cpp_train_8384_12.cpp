#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long int input() {
  long long int n;
  cin >> n;
  return n;
}
long long int poww(long long int a, long long int b, long long int md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const long long int MAXN = 2e5 + 10;
const long long int MAXA = 101;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
const long double PI = 4 * atan((long double)1);
const long double EPS = 1e-10;
long double n, l, v1, v2, k;
bool chk(long double x) {
  long double num = ceil((long double)n / k);
  long double a = (long double)(l - v1 * x) / (long double)(v2 - v1);
  long double b = (long double)l - (long double)v1 * (long double)x;
  long double c = b / ((long double)v1 + (long double)v2);
  return (a * num + c * (num - 1)) <= x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ;
  cin >> n >> l >> v1 >> v2 >> k;
  long double l = 0, r = 1e9;
  while (r - l > EPS) {
    long double mid = (l + r) / 2.0;
    if (chk(mid))
      r = mid;
    else
      l = mid;
  }
  cout << fixed << setprecision(10);
  cout << r << '\n';
  return 0;
}
