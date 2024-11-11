#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k, d;
  cin >> n >> k >> d;
  vector<long long> a;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long mi, si = 0, cc = 0;
  long long u, v = 0, h;
  vector<long long>::iterator it, it1;
  bool b1 = 1;
  while (si < n) {
    it = upper_bound(a.begin(), a.end(), a[si] + d);
    u = it - a.begin();
    if (u + cc - si < k) {
      b1 = 0;
      break;
    }
    if (k - cc + si - 1 > n - 1 ||
        ((k - cc + si - 1 < n) && a[k - cc + si - 1] - a[v] > d)) {
      b1 = 0;
      break;
    }
    if (u > n - 1) {
      break;
    }
    mi = k - cc + si;
    it1 = lower_bound(a.begin(), a.end(), a[u] - d);
    v = it1 - a.begin();
    v = max(mi, v);
    cc = u - v;
    si = u;
  }
  if (b1 == 0) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
  }
  return 0;
}
