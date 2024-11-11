#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int r[n + 1], res = 0;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
    if (n - x <= i) {
      r[i] = y;
    }
    res += r[i];
  }
  cout << res;
}
