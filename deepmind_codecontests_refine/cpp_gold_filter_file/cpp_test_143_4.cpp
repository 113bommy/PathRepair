#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  long long sum = 0;
  vector<long long> ans(n + 1, -1);
  vector<int> ex;
  sort(a.begin(), a.end());
  for (int i = 0; i < n + 1; i++) {
    if (i > 0 && !m.count(i - 1)) {
      if (ex.empty()) {
        break;
      }
      sum += i - 1 - ex.back();
      ex.pop_back();
    }
    while (i > 0 && m.count(i - 1) && m[i - 1] > 1) {
      m[i - 1]--;
      ex.push_back(i - 1);
    }
    ans[i] = sum + (m.count(i) ? m[i] : 0);
  }
  for (int i = 0; i < n + 1; i++) {
    cout << ans[i] << " ";
  }
  cout << nl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
