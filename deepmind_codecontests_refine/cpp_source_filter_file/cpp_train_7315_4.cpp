#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n), b;
    for (long long int i = 0; i < n; i++) cin >> a[i];
    b = a;
    long long int in = 0;
    for (long long int i = 1; i < n; i++) {
      if (a[i] <= a[i - 1]) in++;
    }
    if (in == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
