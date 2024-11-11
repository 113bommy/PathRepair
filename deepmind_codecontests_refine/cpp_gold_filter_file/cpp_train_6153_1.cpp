#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, m;
  cin >> n >> d;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int first, second;
    cin >> first >> second;
    int d4 = (first - 0) * (0 - d) - (second - d) * (d - 0);
    int d1 = (first - d) * (n - d) - (second - 0) * (n - d);
    int d2 = (first - n) * (n - n + d) - (second - n + d) * (n - d - n);
    int d3 = (first - n + d) * (d - n) - (second - n) * (0 - n + d);
    if (d4 <= 0 && d1 <= 0 && d2 <= 0 && d3 <= 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
