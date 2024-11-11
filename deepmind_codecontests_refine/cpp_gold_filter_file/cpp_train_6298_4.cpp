#include <bits/stdc++.h>
using namespace std;
struct tt {
  long long b, e, h;
};
int main() {
  long long n, i, k, m, x, j, p, q, sum = 0;
  cin >> n >> m >> k;
  tt a[m + 6];
  for (i = 0; i < m; i++) {
    cin >> a[i].b >> a[i].e >> a[i].h;
  }
  while (k--) {
    cin >> x;
    for (i = 0; i < m; i++) {
      if (x >= a[i].b && x <= a[i].e) {
        sum += ((x - a[i].b) + a[i].h);
      }
    }
  }
  cout << sum << endl;
}
