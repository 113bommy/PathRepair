#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n, m, f, xp, nb, tt = 0;
  cin >> n >> m;
  for (int i = 0; i <= 1; ++i) {
    f = i;
    xp = n - f;
    nb = m - 2 * f;
    if (nb > 0) {
      f += min(nb, xp / 2);
      tt = max(f, tt);
    }
  }
  cout << tt;
}
