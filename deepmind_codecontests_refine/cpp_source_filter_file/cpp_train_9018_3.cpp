#include <bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9) + 7;
const long long inf = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int x, y;
  cin >> x >> y;
  y--;
  if (x % 2 == 0 && y == 0) return cout << "No", 0;
  if ((x >= y) && ((x % 2) == (y % 2)))
    return cout << "Yes", 0;
  else
    return cout << "No", 0;
}
