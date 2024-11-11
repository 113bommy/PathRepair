#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9;
const long long MB = 60;
const long long MOD = 1e9 + 7;
void solve() {
  long long u, v;
  cin >> u >> v;
  if (u > v || (v - u) % 2) {
    cout << -1;
    return;
  }
  v -= u;
  vector<long long> b(MB);
  for (long long i = 0; i < MB; i++) {
    if ((u >> i) & 1) b[i]++;
  }
  for (long long i = 1; i < MB; i++) {
    if ((v >> i) & 1) {
      b[i - 1] += 2;
    }
  }
  vector<long long> ans;
  while (true) {
    long long res = 0;
    for (long long i = 0; i < MB; i++) {
      if (b[i]) {
        res += (1 << i);
        b[i]--;
      }
    }
    if (!res) break;
    ans.push_back(res);
  }
  cout << ans.size() << '\n';
  for (long long i : ans) cout << i << " ";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
