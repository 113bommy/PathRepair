#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int a[n + 10];
    set<long long int> s;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    long long int ctr = 0;
    for (long long int i = 0; i < n - 1; i++) {
      if (a[i + 1] > a[i]) {
        auto it = s.find(a[i + 1]);
        it--;
        if (a[i] == (*it)) {
          continue;
        }
      }
      ctr++;
    }
    if (ctr <= k)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
