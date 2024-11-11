#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;
const long long int LINF = 1e18;
const long long int MOD = 1e9 + 7;
using namespace std;
long double a, b, c, F, S;
int main() {
  cin >> a >> b >> c;
  F = (-b + sqrt(b * b - 4.0 * a * c)) / 2.0 * a;
  S = (-b - sqrt(b * b - 4.0 * a * c)) / 2.0 * a;
  if (F < S) {
    swap(F, S);
  }
  cout << setprecision(10) << fixed << F << '\n' << S;
  return 0;
}
