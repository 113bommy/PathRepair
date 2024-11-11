#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, m, x, y;
  cin >> n >> d >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    int del = (x > y) ? x - y : y - x;
    int del1 = (n - x > y) ? n - x - y : y - (n - x);
    if (del <= d && del1 <= n - d)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
