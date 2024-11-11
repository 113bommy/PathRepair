#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g;
string str;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> c >> d >> e >> f;
  if (abs(b - a) * d < abs(c - a) * e + abs(b - a) * e + 3 * f)
    cout << "NO";
  else
    cout << "YES";
}
