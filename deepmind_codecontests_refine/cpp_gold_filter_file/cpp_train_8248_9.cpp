#include <bits/stdc++.h>
long long gcdfun(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcdfun(y, x % y);
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k = 1, flag = 0, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int p = *max_element(a.begin(), a.end());
    while (k <= 1024) {
      flag = 0;
      for (int i = 0; i < n; i++) {
        b[i] = (a[i] ^ k);
      }
      sort(b.begin(), b.end());
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
          flag = 1;
          break;
        }
      }
      if (flag == 1)
        k++;
      else {
        cout << k << '\n';
        ans = 1;
        break;
      }
    }
    if (ans == 0) cout << -1 << '\n';
  }
}
