#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int x = n / m, y = n % m;
  for (int i = 0; i < m; i++) {
    if (y) {
      cout << x + 1;
      y--;
    } else {
      cout << x;
    }
    cout << " ";
  }
  return 0;
}
