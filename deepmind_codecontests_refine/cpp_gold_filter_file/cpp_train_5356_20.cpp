#include <bits/stdc++.h>
using namespace std;
int n, p, q, a[302];
int main() {
  cin >> p >> n;
  for (int i = 1; i <= n; i++) {
    cin >> q;
    q %= p;
    if (a[q] == 1) {
      cout << i;
      return 0;
    }
    a[q] = 1;
  }
  cout << -1;
  return 0;
}
