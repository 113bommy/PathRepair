#include <bits/stdc++.h>
using namespace std;
const long long N = 1001;
long long a[N];
long long ans[N];
bool used[N];
long long suff[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n; ++i) {
    for (long long j = n - 1; j >= 0; --j) suff[j] = suff[j + 1] + used[j];
    for (long long j = 0; j < n; ++j) {
      if (used[j]) continue;
      if (suff[j + k] == a[j]) {
        ans[i] = j;
        used[j] = 1;
        break;
      }
    }
  }
  for (long long i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
  cout << '\n';
}
