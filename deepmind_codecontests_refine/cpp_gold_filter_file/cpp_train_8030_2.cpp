#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tt = 1;
  while (tt--) {
    long long int n, x = 0, sum = 0, sum1 = 100000000000, e = 0, k = 1, i, j, q,
                     y = 0, z = 0, m = 0, f = 0, sum2 = 0, d = 0, c = 0;
    cin >> n;
    long long int a[n + 1], b[n + 1];
    a[0] = 0;
    for (i = 1; i < n; i++) cin >> a[i];
    c = (n * (n + 1)) / 2;
    for (i = 0; i < n; i++) {
      sum += a[i];
      a[i] = sum;
    }
    sum = 0;
    for (i = 0; i < n; i++) sum += a[i];
    d = (c - sum) / n;
    for (i = 0; i < n; i++) {
      a[i] += d;
      b[i] = a[i];
    }
    sort(b, b + n);
    for (i = 0; i < n; i++) {
      if ((i + 1) != b[i]) x = 1;
    }
    if (x == 1)
      cout << -1;
    else {
      for (i = 0; i < n; i++) cout << a[i] << " ";
      cout << endl;
    }
  }
}
