#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s[1001], d[1001], i, j, y;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> s[i] >> d[i];
  int x = s[1];
  for (i = 1; i < n; i++) {
    y = s[i + 1];
    while (y < x) y = y + d[i + 1];
    x = y;
  }
  cout << x << endl;
  return 0;
}
