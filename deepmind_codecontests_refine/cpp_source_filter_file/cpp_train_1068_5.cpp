#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long i, j;
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    set<long long> s;
    long long comp = k, ans = 1;
    for (i = 0; i < n; i++) {
      s.insert(a[i]);
      if (s.size() > comp) {
        ans++;
        comp = comp + (k - ans + 1);
      }
    }
    if (s.size() <= k)
      cout << 1 << endl;
    else if (k == 1)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}
