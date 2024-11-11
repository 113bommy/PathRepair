#include <bits/stdc++.h>
using namespace std;
int n, m, a1, b1, a2, b2;
bool is_corner(int hi1, int hi2) {
  if (hi1 == 1 && hi2 == 1) return true;
  if (hi1 == n && hi2 == m) return true;
  if (hi1 == 1 && hi2 == m) return true;
  if (hi1 == n && hi2 == 1) return true;
  return false;
}
int main() {
  cin >> n >> m >> a1 >> b1 >> a2 >> b2;
  if (abs(a1 - a2) >= 5 || abs(b1 - b2) >= 5)
    cout << "Second";
  else if (is_corner(a1, b1) && is_corner(a2, b2) &&
           (abs(a1 - a2) > 3 || abs(b1 - b2) > 3))
    cout << "Second";
  else if (abs(a1 - a2) + abs(b1 - b2) >= 7)
    cout << "Second";
  else
    cout << "First";
  return 0;
}
