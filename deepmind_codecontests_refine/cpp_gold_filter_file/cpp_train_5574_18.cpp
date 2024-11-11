#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y;
  cin >> n >> m;
  int a = n, b = 1;
  while (m--) {
    cin >> x >> y;
    if (x < y) swap(x, y);
    a = min(x, a), b = max(y, b);
  }
  cout << max(0, a - b);
}
