#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long i, j, k, n, m, q;
  cin >> n >> m >> q;
  long long suma = 0;
  for (i = 0; i < n; i++) {
    cin >> j;
    if (i & 1 == 1) {
      suma -= j;
    } else {
      suma += j;
    }
  }
  long long b[m];
  for (i = 0; i < m; i++) {
    cin >> b[i];
  }
  set<long long> sb;
  set<long long>::iterator it;
  long long sumb = 0;
  for (i = 0; i < n; i++) {
    if (i & 1 == 1) {
      sumb -= b[i];
    } else {
      sumb += b[i];
    }
  }
  sb.insert(-sumb);
  for (i = n; i < m; i++) {
    sumb -= b[i - n];
    sumb *= -1;
    if (n & 1 == 0) {
      sumb -= b[i];
    } else {
      sumb += b[i];
    }
    sb.insert(-sumb);
  }
  it = sb.upper_bound(-suma);
  if (it == sb.end()) {
    cout << abs(*prev(it) + suma) << '\n';
  } else {
    if (it == sb.begin()) {
      cout << abs(*it + suma) << '\n';
    } else {
      cout << min(abs(*it + suma), abs(*prev(it) + suma)) << '\n';
    }
  }
  while (q--) {
    long long l, r, x;
    cin >> l >> r >> x;
    if ((r - l) % 2 == 0) {
      if (l & 1 == 1) {
        suma += x;
      } else {
        suma -= x;
      }
    }
    it = sb.upper_bound(-suma);
    if (it == sb.end()) {
      cout << abs(*prev(it) + suma) << '\n';
    } else {
      if (it == sb.begin()) {
        cout << abs(*it + suma) << '\n';
      } else {
        cout << min(abs(*it + suma), abs(*prev(it) + suma)) << '\n';
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
