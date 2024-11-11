#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long i, j, ans = 0, n, maxx = 1;
    map<long, long> c;
    cin >> n;
    long long a[n], b[n];
    for (i = 0; i < n; i++) {
      cin >> b[i];
      a[i] = b[i];
    }
    sort(a, a + n);
    for (i = 0; i < n; i++) {
      c[b[i]] = i;
      b[i] = i;
    }
    for (i = 0; i < n; i++) {
      a[i] = c[a[i]];
    }
    ans = 1;
    for (i = 0; i < n - 1; i++) {
      if (a[i + 1] > a[i]) {
        ans++;
        maxx = max(maxx, ans);
      } else {
        ans = 1;
      }
    }
    cout << n - maxx << '\n';
  }
}
