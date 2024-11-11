#include <bits/stdc++.h>
using namespace std;
long long x, mx, le[300005], chan[300005], j, n, kq, tong[300005], t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  chan[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    j = 0;
    while (x) {
      j = j + (x % 2);
      x /= 2;
    }
    tong[i] = tong[i - 1] + j;
    chan[i] = chan[i - 1];
    le[i] = le[i - 1];
    if (tong[i] % 2 == 0)
      chan[i]++;
    else
      le[i]++;
  }
  for (int i = 1; i <= n; ++i) {
    mx = 0;
    x = i - 130;
    if (x < 0) x = 0;
    for (int j = i; j > x; --j) {
      mx = max(mx, tong[j] - tong[j - 1]);
      t = tong[i] - tong[j - 1];
      if (t % 2 == 0 && t >= mx * 2) kq++;
    }
    if (i - 130 > 0) {
      if (tong[i] % 2)
        kq += le[x - 1];
      else
        kq += chan[x - 1];
    }
  }
  cout << kq;
  return 0;
}
