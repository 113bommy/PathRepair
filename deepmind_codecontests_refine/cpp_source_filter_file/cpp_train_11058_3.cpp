#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[100010];
int b[100010], c[100010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    sort(a, a + 2 * n);
    int ib = 0, ic = 0;
    bool f = 0;
    if (n % 2 == 0) f = 1;
    for (int i = 0; i < 2 * n; i++)
      if (i & 1 or f)
        c[ic++] = a[i], f = 0;
      else
        b[ib++] = a[i];
    cout << abs(c[n / 2] - b[n / 2]) << endl;
  }
}
