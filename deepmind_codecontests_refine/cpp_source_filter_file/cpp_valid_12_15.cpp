#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m == 1 && k > 0) {
    cout << "NO\n";
    return;
  }
  if (n % 2 == 1) {
    int bottomdominoes = m / 2;
    k -= bottomdominoes;
    if (k < 0 || (k % 2) == 1) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
  } else {
    if (k % 2 == 1) {
      cout << "NO\n";
      return;
    }
    int maxdominoes = n * m / 2;
    if (k > maxdominoes) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
  }
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
