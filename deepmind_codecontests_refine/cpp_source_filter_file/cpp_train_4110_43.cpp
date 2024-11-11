#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int f = max(3 * a / 10, a - (a / 250 * c));
  int p = max(3 * b / 10, b - (b / 250 * d));
  if (p > f) cout << "Misha";
  if (f == p) cout << "Tie";
  if (f > p) cout << "Vasya";
}
