#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u,
      v, w, x, y, z;
  cin >> n;
  c = 0;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a == 0) c++;
  }
  if (n == 1) {
    if (c == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  } else {
    if (c == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
