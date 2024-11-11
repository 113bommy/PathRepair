#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
long long n, p, b, L, m, q = 0, per = 0, k = 0, res = -10000000000000, sum = 0,
                         ras = 0, atc = 0, def = 0;
long long a[300009], t[300009], d[300009], l[100009], r[100009];
int fi, x, y;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    t[a[i]] = i;
  }
  long long i;
  cin >> i;
  for (int j = 0; j < i; j++) {
    cin >> fi >> x >> y;
    --x, --y;
    if (fi == 1) {
      m = 1;
      for (int u = x + 1; u < y; u++) {
        if (t[u] < t[u - 1]) ++m;
      }
      cout << m << "\n";
    } else {
      swap(t[a[x]], t[a[y]]);
      swap(a[x], a[y]);
    }
  }
  int kol234;
  cin >> kol234;
}
