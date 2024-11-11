#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, r, Sall, Sk;
  cin >> n >> k >> l >> r >> Sall >> Sk;
  int a[2000];
  int x = Sk / k;
  int count = Sk % k;
  for (int i = 1; i <= k; ++i) {
    a[i] = x;
  }
  for (int i = 1; i <= count; ++i) {
    if (count > 0) {
      count--;
      a[i]++;
    }
  }
  int range;
  int y;
  int co;
  if (n != k) {
    range = Sall - Sk;
    y = range / (n - k);
    co = range % (n - k);
    for (int i = k + 1; i <= n; ++i) {
      a[i] = y;
    }
    for (int i = k + 1; i <= n; ++i) {
      if (co > 0) {
        a[i]++;
        co--;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  return 0;
}
