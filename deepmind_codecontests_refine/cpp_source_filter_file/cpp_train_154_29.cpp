#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
double EPS = 1e-7;
vector<string> v = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                    "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                    "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
long double solve1(long double a, long double b, long double c) {
  return pow(b, c) * log(a);
}
long double solve2(long double a, long double b, long double c) {
  return c * b * log(a);
}
void naive(long double a, long double b, long double c) {
  int idx = 0;
  long double best = -0.1;
  for (int i = (0); i < (3); ++i) {
    if (i == 1) {
      swap(a, b);
    } else if (i == 2) {
      swap(a, c);
    }
    if (solve1(a, b, c) > best + EPS) {
      idx = 0 + i * 4;
      best = solve1(a, b, c);
    }
    if (solve1(a, c, b) > best + EPS) {
      idx = 1 + i * 4;
      best = solve1(a, c, b);
    }
    if (solve2(a, b, c) > best + EPS) {
      idx = 2 + i * 4;
      best = solve2(a, b, c);
    }
    if (solve2(a, c, b) > best + EPS) {
      idx = 3 + i * 4;
      best = solve2(a, c, b);
    }
  }
  cout << v[idx];
  exit(0);
}
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  naive(a, b, c);
}
