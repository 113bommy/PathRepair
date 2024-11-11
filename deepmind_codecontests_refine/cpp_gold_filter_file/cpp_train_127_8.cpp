#include <bits/stdc++.h>
using namespace std;
long long t;
long long n, m;
void Solves() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    long long a[n + 5], b[m + 5], ans = 0;
    map<long long, long long> Count;
    long long result;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      Count[a[i]]++;
    }
    for (long long i = 0; i < m; i++) {
      cin >> b[i];
      if (Count[b[i]] > 0) {
        ans = 1;
        result = b[i];
      }
    }
    if (ans != 0) {
      cout << "YES" << endl;
      cout << ans << " " << result << endl;
    } else
      cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  Solves();
  return 0;
}
