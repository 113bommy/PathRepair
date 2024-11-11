#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long d, n, s = 0;
  cin >> d >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 1; i < n; i++) {
    s += d - a[i];
  }
  cout << s;
}
