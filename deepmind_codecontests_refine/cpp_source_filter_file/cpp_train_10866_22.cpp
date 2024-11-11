#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    long long n, m;
    cin >> n >> m;
    long long a[n];
    vector<long long> in(n), d(n);
    for (long long i = 0; i <= n - 1; i++) {
      cin >> a[i];
    }
    in[n - 1] = d[n - 1] = n - 1;
    for (long long i = n - 2; i >= 0; i--) {
      if (a[i] <= a[i + 1])
        in[i] = a[i + 1];
      else
        in[i] = i;
      if (a[i] >= a[i + 1])
        d[i] = d[i + 1];
      else
        d[i] = i;
    }
    for (long long i = 0; i < m; i++) {
      long long l, r;
      cin >> l >> r;
      l--;
      r--;
      if (d[in[l]] >= r)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
}
