#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, lf, rg;
long long a[N], k[N], sum;
int binary_search(long long pos) {
  while (true) {
    if (abs(rg - lf) <= 10) {
      int t = -1;
      for (int i = lf; i <= rg; i++) {
        if ((a[i] - sum) > pos) {
          t = i;
          break;
        }
      }
      if (t == -1) {
        lf = 1;
        rg = n;
        sum = 0;
        return n;
      } else {
        sum += (long long)pos;
        lf = t;
        rg = n;
        return n - t + 1;
      }
    }
    int je = (lf + rg) / 2;
    if ((a[je] - sum) > pos)
      rg = je;
    else
      lf = je;
  }
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += (long long)a[i - 1];
  }
  for (int i = 1; i <= q; i++) {
    cin >> k[i];
    k[i] += (long long)k[i - 1];
  }
  lf = 1;
  rg = n;
  for (int i = 1; i <= q; i++)
    cout << binary_search((long long)k[i] - k[i - 1]) << endl;
  cout << endl;
  return 0;
}
