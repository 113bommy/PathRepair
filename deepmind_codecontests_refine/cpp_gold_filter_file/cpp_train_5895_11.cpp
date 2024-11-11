#include <bits/stdc++.h>
using namespace std;
int n, q, m;
long long a[200005];
struct Perechi {
  int op, st, dr;
};
Perechi t[200005];
void Citire() {
  int i;
  cin >> n >> q >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= q; i++) cin >> t[i].op >> t[i].st >> t[i].dr;
}
void Rezultat() {
  int i, j, x;
  for (i = 1; i <= m; i++) {
    cin >> x;
    for (j = q; j >= 1; j--) {
      if (t[j].st <= x && x <= t[j].dr) {
        if (t[j].op == 1) {
          if (x == t[j].st)
            x = t[j].dr;
          else
            x--;
        } else
          x = t[j].dr - x + t[j].st;
      }
    }
    cout << a[x] << " ";
  }
}
int main() {
  Citire();
  Rezultat();
  return 0;
}
