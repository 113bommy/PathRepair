#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long add = 0;
    long long a[n + 1];
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    while (m--) {
      long long ty;
      cin >> ty;
      if (ty == 1) {
        long long idx, val;
        cin >> idx >> val;
        long long exclude = add;
        a[idx] = val;
        a[idx] -= exclude;
      } else if (ty == 2) {
        long long i;
        cin >> i;
        add += i;
      } else {
        long long idx;
        cin >> idx;
        cout << a[idx] + add << '\n';
      }
    }
  }
  return 0;
}
