#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<long long>;
using vpi = vector<pair<long long, long long>>;
using pi = pair<long long, long long>;
const long long nax = 1e5 + 7;
const long long mod = 1e9 + 7;
const long long inf = numeric_limits<long long>::max() - (long long)9e6;
long long n;
void test() {
  cin >> n;
  vi v(n + 2);
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
  }
  vi Ldes(n + 2), Rdes(n + 2);
  for (long long i = 1; i <= n; i++) {
    Ldes[i] = min(Ldes[i - 1] + 1, v[i]);
  }
  for (long long i = n - 1; i >= 0; i--) {
    Rdes[i] = min(Rdes[i + 1] + 1, v[i]);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans = max(ans, min(Ldes[i], Rdes[i]));
  }
  cout << ans;
}
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  while (T--) {
    test();
    cout << "\n";
  }
  return 0;
}
