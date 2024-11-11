#include <bits/stdc++.h>
using namespace std;
long long r[5005], c[5005], r_occr[5005], c_occr[5005];
int main() {
  long long n, m, k, i, j, temp, x, y;
  cin >> n >> m >> k;
  memset(r, 0, sizeof(r));
  memset(c, 0, sizeof(c));
  memset(r_occr, 0, sizeof(r_occr));
  memset(c_occr, 0, sizeof(c_occr));
  for (i = 1; i <= k; i++) {
    cin >> x >> y >> temp;
    if (x == 1) {
      r[y] = temp;
      r_occr[y] = i;
    } else {
      c[y] = temp;
      c_occr[y] = i;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (r_occr[i] > c_occr[j])
        cout << r[i] << " ";
      else
        cout << c[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
