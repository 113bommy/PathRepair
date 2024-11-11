#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, ans;
int main() {
  cin >> a >> b >> c >> d;
  int x = min(a, min(b, c)), y = max(a, max(b, c));
  int z = a + b + c - x - y;
  if (z - x < d) ans += d - (z - x);
  if (y - z < d) ans = +d - (y - z);
  cout << ans;
}
