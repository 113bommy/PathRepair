#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 2e5 + 1;
const long long int INF = 1e16;
const long long int MOD = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<long long int> mod_class;
  for (long long int i = 0; i < n; i++) {
    long long int dest_class = i + a[i];
    if (dest_class < 0) {
      long long int k = ceil((1.0 * dest_class) / n);
      dest_class += (k * n);
    } else {
      dest_class %= n;
    }
    mod_class.insert(dest_class);
  }
  long long int sz = mod_class.size();
  if (sz == n) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
