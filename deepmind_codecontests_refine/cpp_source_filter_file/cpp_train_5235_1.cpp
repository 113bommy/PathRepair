#include <bits/stdc++.h>
using namespace std;
long long a[300200], b[300009], cc[300009];
map<long long, long long> mp;
int main() {
  cin.sync_with_stdio(false);
  long long i, j, k, l, c, v, n, m, r, t, tt;
  long long x1, x2, y1, y2, x3, x4, x5, x6;
  string s, s34, s1, s2, s3;
  cin >> tt;
  while (tt--) {
    cin >> n;
    cin >> k;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (i = n - 2, j = 0; i >= 0; i--) {
      if (j == k)
        break;
      else {
        a[n - 1] += a[i];
        a[i] = 0;
      }
      j++;
    }
    cout << a[n - 1] - a[0] << endl;
  }
}
