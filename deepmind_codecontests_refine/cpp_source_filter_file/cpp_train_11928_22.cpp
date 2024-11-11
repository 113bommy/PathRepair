#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, x, c, d, ch = 0, caser = 0, lol = 0, sum = 0, rating = -1,
                     upper = 1e9, lower = -1e9;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c >> d;
    if (i == 0) {
      if (d == 1)
        lower = 1900;
      else
        upper = 1899;
    } else {
      if (d == 2) {
        upper = min(upper, sum + 1899);
      } else {
        lower = max(lower, lower + 1900);
      }
    }
    sum -= c;
  }
  if (upper == 1e9)
    cout << "Infinity\n";
  else if (lower > upper)
    cout << "Impossible\n";
  else
    cout << upper - sum << endl;
}
