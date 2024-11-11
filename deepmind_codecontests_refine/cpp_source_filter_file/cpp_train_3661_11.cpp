#include <bits/stdc++.h>
using namespace std;
long long n, k, t, m, q, flag = 0, count = 0;
int main() {
  ios::sync_with_stdio(false);
  t = 1;
  while (t--) {
    cin >> n >> q;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long hatadiye[n], c[n], d[n], temp = a[0];
    for (int i = 0; i < n - 1; i++) {
      c[i] = temp;
      d[i] = a[i + 1];
      if (temp > a[i + 1]) {
        hatadiye[i] = a[i + 1];
      } else {
        hatadiye[i] = temp;
        temp = a[i + 1];
      }
    }
    for (int i = 0; i < q; i++) {
      cin >> k;
      if (k < n)
        cout << c[k - 1] << " " << d[k - 1] << endl;
      else
        cout << temp << " " << hatadiye[k % (n - 1) - 1] << endl;
    }
  }
  return 0;
}
