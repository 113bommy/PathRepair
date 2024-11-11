#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f;
int main() {
  cin >> a >> b >> c >> d >> e >> f;
  if ((f - d) * (c - a) == (d - b) * (e - c)) {
    cout << "NO" << endl;
    return 0;
  }
  if ((d - b) * (d - b) + (c - a) * (c - a) ==
      (f - d) * (f - d) + (e - c) * (e - c)) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
