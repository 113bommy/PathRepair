#include <bits/stdc++.h>
using namespace ::std;
const int MOD = 1000000007, INF = 1e9, MAX = 2e6;
long long int a[MAX], b[MAX], c[MAX];
vector<long long int> v;
int main() {
  std::ios_base::sync_with_stdio(false);
  long long int i, j, k, n, l;
  cin >> n >> l;
  long long int ans = -1e9;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      long long int s = 0, p = 0;
      long long int sum1 = 0, sum2 = 0;
      for (k = 0; k < n; k++) {
        if (k < i || k > j) {
          c[s] = a[k];
          s++;
          sum2 += a[k];
        } else {
          b[p] = a[k];
          sum1 += a[k];
          p++;
        }
      }
      sort(b, b + p);
      sort(c, c + s);
      long long int sz = min(p, s);
      sz = min(sz, l);
      long long int sum3 = 0, sum4 = 0;
      for (k = 0; k < sz; k++) {
        ans = max(ans, sum1 - sum3 + sum4);
        sum3 += b[k];
        sum4 += c[k];
      }
      ans = max(ans, sum1 - sum3 + sum4);
    }
  }
  cout << ans << endl;
}
