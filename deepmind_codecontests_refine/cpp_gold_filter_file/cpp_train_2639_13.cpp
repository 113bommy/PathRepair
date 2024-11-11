#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-4;
const int inf = 1e9;
const long double PI = acos(-1);
int mod = (int)998244353;
const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int a228 = 18;
const long long kekmod = 1791791791;
const long long bestmod = 1148822869;
const long long secmod = (int)1e9 + 113;
vector<long long> mods = {kekmod, bestmod, mod, MOD9, 1000000007};
vector<long long> hashpows = {29, 31, 37, 43, 47, 53, 179, 229};
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count() +
            228 + 'i' + 'q' + 1337 + 1488);
long long MOD = mods[rnd() % mods.size()];
long long hashpow = hashpows[rand() % hashpows.size()];
long double hypot(long double a, long double b, long double c, long double d) {
  return sqrt(((a - c) * (a - c)) + ((b - d) * (b - d)));
}
long double gcd(long double a, long double b) {
  while (abs(b) > EPS) {
    a -= floor(a / b) * b;
    swap(a, b);
  }
  return a;
}
long double getang(long double a, long double b, long double c) {
  return acos(-(c * c - a * a - b * b) / (2 * a * b));
}
signed main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  srand(time(NULL));
  long double a, b, c;
  long double x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  a = hypot(x1, y1, x2, y2);
  b = hypot(x2, y2, x3, y3);
  c = hypot(x3, y3, x1, y1);
  long double a1 = getang(a, b, c);
  long double a2 = getang(b, c, a);
  long double a3 = getang(a, c, b);
  long double mere = gcd(gcd(a1, a2), a3);
  int n = (int)((PI + EPS) / mere);
  long double R = c / sin(a1) / 2;
  long double tang = PI * 2 / n;
  long double ans = n * (0.5 * R * R * sin(tang));
  cout << fixed << setprecision(20) << ans;
}
