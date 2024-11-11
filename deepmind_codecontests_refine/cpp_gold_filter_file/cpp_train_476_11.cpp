#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f, g;
  std::cin >> a >> b >> c >> d >> e;
  f = a * b + 2 * d;
  g = a * c + 2 * e;
  if (f < g)
    cout << "First";
  else if (f > g)
    cout << "Second";
  else
    cout << "Friendship";
  return 0;
}
