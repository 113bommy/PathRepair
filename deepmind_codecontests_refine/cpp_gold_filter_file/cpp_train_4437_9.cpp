#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 2e6 + 2;
int a[N];
int res[N];
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > b;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    b.push_back({num, i});
  }
  sort(a, a + n, greater<int>());
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    res[b[i].second] = a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
