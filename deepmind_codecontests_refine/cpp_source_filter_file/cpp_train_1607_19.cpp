#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, f, g;
  cin >> a >> b >> c;
  cin >> d >> e >> f;
  g = (a - d) * (a - d) + (b - e) * (b - e) + (c - f) * (c - f);
  if (g == 3)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
