#include <bits/stdc++.h>
using namespace std;
int n, s, x, y, a[3], d[3];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s >> x >> y;
    a[s] += x;
    d[s] += y;
  }
  for (int i = 1; i <= 2; ++i)
    if (a[i] >= d[i])
      cout << "ALIVE\n";
    else
      cout << "DEAD\n";
  return 0;
}
