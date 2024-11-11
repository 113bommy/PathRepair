#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long mod1 = 1e9 + 7;
const long long N = 4e5 + 2;
long long ans = 0, n, a[N], k;
map<long long, long long> m;
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long i = 0, j = 0;
  while (j < n) {
    m[a[j]]++;
    if (m[a[j]] == k) {
      while (m[a[i]] != k) {
        m[a[i]]--;
        i++;
        ans += n - j;
      }
      m[a[i]]--;
      i++;
      ans += n - j;
    }
    j++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
