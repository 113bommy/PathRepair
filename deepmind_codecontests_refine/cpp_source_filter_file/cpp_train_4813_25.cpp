#include <bits/stdc++.h>
using namespace std;
long long int P = 1000000007;
long long int arraySortedOrNot(long long int arr[], long long int n) {
  if (n == 1 || n == 0) return 1;
  if (arr[n - 1] < arr[n - 2]) return 0;
  return arraySortedOrNot(arr, n - 1);
}
long long int a[200001][26];
int main() {
  long long int i, j, k, l, m, n, o, p, q, r, t, a, b, c, va, vb, vc;
  cin >> t;
  while (t--) {
    long long int ans = 10000000000000000, vala = -1, valb = -1, valc = -1;
    cin >> a >> b >> c;
    k = 1;
    while (k <= 10000) {
      o = 0;
      for (l = 2 * k; l <= 10000; l += k) {
        q = (c - 1) / l;
        q *= l;
        o = fabs(a - k) + fabs(b - l) + fabs(c - q);
        if (o < ans) {
          ans = o;
          vala = k;
          valb = l;
          valc = q;
        }
        q += l;
        o = fabs(a - k) + fabs(b - l) + fabs(c - q);
        if (o < ans) {
          ans = o;
          vala = k;
          valb = l;
          valc = q;
        }
      }
      k++;
    }
    cout << ans << endl;
    cout << vala << " " << valb << " " << valc << endl;
  }
  return 0;
}
