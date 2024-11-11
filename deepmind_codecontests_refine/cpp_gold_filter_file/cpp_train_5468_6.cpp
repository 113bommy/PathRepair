#include <bits/stdc++.h>
using namespace std;
long n, m;
int t, x;
long a[200005];
long b[200005];
struct C {
  int t;
  long x;
} c[200005];
int nc = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> t >> x;
    while (nc > 0 && c[nc - 1].x <= x) nc--;
    c[nc].x = x;
    c[nc].t = t;
    nc++;
  }
  int nb = c[0].x;
  for (int i = 0; i < nb; i++) b[i] = a[i];
  sort(b, b + nb);
  int l = 0, r = nb - 1;
  c[nc].x = 0;
  c[nc].t = 1;
  for (int i = 0; i < nc; i++) {
    if (c[i].t == 1) {
      while (nb > c[i + 1].x) {
        nb--;
        a[nb] = b[r--];
      }
    } else {
      while (nb > c[i + 1].x) {
        nb--;
        a[nb] = b[l++];
      }
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
