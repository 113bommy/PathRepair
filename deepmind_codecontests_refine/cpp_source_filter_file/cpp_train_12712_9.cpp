#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<long long int> pr_a(n);
  long long int s = 0;
  for (long long int i = 0; i < n; ++i) {
    s += a[i];
    pr_a[i] = s;
  }
  long long int m = 0;
  for (long long int l = 0; l < n; ++l) {
    for (long long int r = l; r < n; ++r) {
      long long int cur_sum = pr_a[r] - (l > 0 ? pr_a[l - 1] : 0);
      if (cur_sum > 100 * (r - l)) {
        m = max(m, r - l);
      }
    }
  }
  cout << m << endl;
}
