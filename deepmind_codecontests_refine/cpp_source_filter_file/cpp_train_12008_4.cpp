#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:33554432")
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-8;
const int INF = (1 << 30) - 1;
int n, m, x1, yyyyy1, x2, y2;
void quit1() {
  cout << "First";
  exit(0);
}
void quit2() {
  cout << "Second";
  exit(0);
}
int main() {
  cin >> m >> n >> x1 >> yyyyy1 >> x2 >> y2;
  m = abs(x1 - x2);
  n = abs(yyyyy1 - y2);
  if (m > n) swap(m, n);
  if (m <= 1) {
    if (n <= 4)
      quit1();
    else
      quit2();
  }
  if (m == 2) {
    if (n <= 3)
      quit1();
    else
      quit2();
  }
  quit2();
  return 0;
};
