#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int INF = 10000000;
const long long int MAX_N = 1e6 + 2;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(k + 1);
  for (int i = 1; i < k + 1; ++i) cin >> v[i];
  vector<int> a(n + 1, 0);
  for (int i = 1; i < k; ++i) {
    for (int j = v[i]; j <= n; ++j) {
      if (a[j] == 0) a[j] = v[i];
    }
  }
  for (int i = 1; i < n + 1; ++i) cout << a[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) solve();
}
