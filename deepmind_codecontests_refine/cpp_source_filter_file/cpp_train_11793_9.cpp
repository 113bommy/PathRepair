#include <bits/stdc++.h>
const int MAX = 400010;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-10;
const long double PI = acosl(-1.0);
using namespace std;
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, R, r;
  cin >> n >> R >> r;
  if (n == 1) {
    if (R >= r)
      yes();
    else
      no();
  } else if (n == 2) {
    if (R >= 2 * r)
      yes();
    else
      no();
  } else {
    long double a = 180.0 / n;
    long double x = sin(a * PI / 180.0) * (R - r);
    if (x - r >= EPS)
      yes();
    else
      no();
  }
  return 0;
}
