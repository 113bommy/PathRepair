#include <bits/stdc++.h>
using namespace std;
pair<long long, int> a[100000 + 5];
int n, m;
long long k, t;
int main() {
  int i;
  while (cin >> n >> k) {
    for (i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i + 1;
    }
    while (k > n) {
      m = 0;
      t = k / n;
      k -= t * n;
      for (i = 0; i < n; i++) {
        a[i].first -= t;
        if (a[i].first <= 0)
          k -= a[i].first;
        else {
          a[m].first = a[i].first;
          a[m].second = a[i].second;
          m++;
        }
      }
      n = m;
      if (n == 0) break;
    }
    if (n == 0 && k > 0)
      cout << -1 << endl;
    else {
      for (m = 0, i = k; i < n; i++) {
        if (a[i].first > 0) {
          if (m) cout << ' ';
          cout << a[i].second;
          m++;
        }
      }
      for (i = 0; i < k; i++) {
        if (a[i].first > 1) {
          if (m) cout << ' ';
          cout << a[i].second;
          m++;
        }
      }
      cout << endl;
    }
  }
}
