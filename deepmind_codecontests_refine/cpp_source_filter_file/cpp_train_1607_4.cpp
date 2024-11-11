#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if ((a - d) * (b - e) * (d - f) == 0)
    cout << "YES";
  else
    cout << "NO";
}
