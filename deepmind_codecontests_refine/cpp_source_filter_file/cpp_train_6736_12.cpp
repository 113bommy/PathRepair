#include <bits/stdc++.h>
using namespace std;
const int _max = 1e5 + 50;
int a[_max];
int main() {
  int n, k, lr;
  while (cin >> n >> k >> lr) {
    int m = n * k;
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a + 1, a + m + 1);
    if (a[n] - a[1] > lr) {
      cout << "0" << endl;
      continue;
    }
    int cnt = a[1] + lr;
    int l = 1, r = m, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (cnt < a[mid])
        r = mid;
      else
        l = mid + 1;
    }
    mid = (l + r) >> 1;
    if (cnt < a[mid]) mid--;
    cnt = 0;
    if (k - 1 >= 1) {
      l = (m - mid) / (k - 1);
      for (int i = 0; i < l; i++) {
        cnt += a[mid - i];
      }
      mid -= l;
      l = (m - (mid + l)) % (k - 1);
      l = k - 1 - l;
      mid -= l;
      cnt += a[mid];
      mid--;
    }
    while (mid >= 1) {
      mid -= (k - 1);
      cnt += a[mid--];
    }
    cout << cnt << endl;
  }
  return 0;
}
