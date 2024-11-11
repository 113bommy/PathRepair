#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, mn;
int main() {
  cin >> a >> b >> c >> d >> e >> f;
  mn = a;
  if (b < mn) mn = b;
  if (c < mn) mn = c;
  if (d < mn) mn = d;
  cout << max(min(f, mn) - e + 1, 0);
}
