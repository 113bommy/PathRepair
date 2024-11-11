#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, t, v, x, y, q;
  cin >> n >> m;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long cont = 0;
  for (long long z = 0; z < m; z++) {
    cin >> t;
    if (t == 1) {
      cin >> v >> x;
      a[v - 1] = x - cont;
    } else if (t == 2) {
      cin >> y;
      cont += y;
    } else {
      cin >> q;
      cout << a[q - 1] + cont << endl;
    }
  }
}
