#include <bits/stdc++.h>
using namespace std;
const int oo = 2147483647;
int n, d, l, a[105];
int main() {
  int tq, i;
  cin >> n >> d >> l;
  if (d >= 0) {
    tq = 0;
    for (i = 1; i <= n; ++i) {
      if (i % 2) {
        a[i] = l;
        tq += l;
      } else {
        a[i] = 1;
        --tq;
      }
    }
    if (tq < d) {
      cout << -1 << endl;
      return 0;
    } else {
      tq -= d;
      for (i = 1; i <= n; ++i) {
        if (i % 2) {
          a[i] -= min(tq, l - 1);
          tq -= min(tq, l - 1);
        } else {
          a[i] += min(tq, l - 1);
          tq -= min(tq, l - 1);
        }
      }
    }
  } else {
    tq = 0;
    for (i = 1; i <= n; ++i) {
      if (i % 2) {
        a[i] = 1;
        ++tq;
      } else {
        a[i] = l;
        tq -= l;
      }
    }
    if (tq > d) {
      cout << -1 << endl;
      return 0;
    } else {
      tq -= d;
      for (i = 1; i <= n; ++i) {
        if (i % 2) {
          a[i] -= max(tq, 1 - l);
          tq -= max(tq, 1 - l);
        } else {
          a[i] += max(tq, 1 - l);
          tq -= max(tq, 1 - l);
        }
      }
    }
  }
  for (i = 1; i <= n; ++i) cout << a[i] << " ";
  cout << endl;
}
