#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> pos;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i + 1);
  }
  vector<int> res(n + 1, n + 1);
  for (int i = 1; i <= n; i++) {
    if (!pos.count(i)) {
      continue;
    }
    vector<int> &p = pos[i];
    int d = p[0];
    for (int j = 1; j < p.size(); j++) {
      d = max(d, p[j] - p[j - 1]);
    }
    d = max(d, n - p.back() + 1);
    res[d] = min(res[d], i);
  }
  for (int i = 2; i <= n; i++) {
    res[i] = min(res[i], res[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    cout << (res[i] == n + 1 ? -1 : res[i]) << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
