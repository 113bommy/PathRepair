#include <bits/stdc++.h>
using namespace std;
long long int n, i, j, k, ans, t, flag, m, x, y, r, lo, hi;
long long int a[500300], b[500002], c[200000], d[200000];
pair<long long int, long long int> row[20008];
pair<long long int, long long int> col[20008];
map<long long int, long long int> m1;
vector<long long int> v;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  j = 0;
  for (i = 0; i < m; i++) {
    cin >> t >> r;
    while (j > 0 && r >= b[j - 1]) {
      j--;
    }
    b[j] = r;
    c[j] = t;
    j++;
  }
  lo = 0;
  hi = b[0];
  b[j] = 0;
  j++;
  k = j;
  for (i = 0; i < hi; i++) {
    d[i] = a[i];
  }
  sort(d, d + hi);
  hi--;
  for (i = 1; i < k; i++) {
    for (j = b[i - 1]; j > b[i]; j--) {
      if (c[i - 1] == 1) {
        a[j - 1] = d[hi];
        hi--;
      } else {
        a[j - 1] = d[lo];
        lo++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
