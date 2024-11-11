#include <bits/stdc++.h>
using namespace std;
bool is_prime(short m) {
  if (m == 2 || m == 3) {
    return true;
  }
  if (m % 2 == 0 || m % 3 == 0 || m < 2) {
    return false;
  }
  for (short nr = 6; nr * nr <= m; nr += 6) {
    if (m % (nr - 1) == 0 || m % (nr + 1) == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  short n, m;
  cin >> n >> m;
  for (short nr = n + 1;; ++nr) {
    if (is_prime(nr)) {
      if (nr == m) {
        cout << "YES";
      } else {
        cout << "NO";
      }
      return 0;
    }
  }
}
