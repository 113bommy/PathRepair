#include <bits/stdc++.h>
using namespace std;
const string LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const long long LINF = (long long)9e18 + 7;
bool insert(int k, int x1, int x2) { return (k >= x1 && k <= x2); }
const bool is_testing = false;
const int MAXN = 1e5 + 8;
long double a, b, c, d;
long double f(long double p, long double t) {
  return max(3 * p / 10, p - p * t / 250);
}
int main() {
  if (is_testing) {
    freopen("INPUT.in", "r", stdin);
  }
  cin >> a >> b >> c >> d;
  if (f(a, c) > f(b, d))
    cout << "Misha";
  else if (f(a, c) < f(b, d))
    cout << "Vasya";
  else
    cout << "Tie";
}
