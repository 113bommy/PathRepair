#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, a, b, cnt = 0, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    if ((b - a) >= 2) {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
