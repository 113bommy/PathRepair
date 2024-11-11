#include <bits/stdc++.h>
#pragma gcc optimize(O3)
using namespace std;
const long long INF = (long long)(1e18);
const long long inf = 1e9 + 7;
long double eps = 1e-10;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long mod = 998244353;
long long pows(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 1) return (a * pows(a, b - 1)) % mod;
  if (b % 2 == 0) {
    long long c = pows(a, b / 2);
    return (c * c) % mod;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<set<int>> g(3 * n);
    vector<pair<int, int>> edge(m);
    vector<int> used(3 * n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      edge[i] = {a, b};
      g[a].insert(b);
      g[b].insert(a);
    }
    vector<int> ans;
    for (int i = 0; i < m; i++) {
      int a = edge[i].first, b = edge[i].second;
      if (used[a] == 0 && used[b] == 0) {
        ans.push_back(i);
        used[a] = 1;
        used[b] = 1;
      }
    }
    if (ans.size() >= n) {
      cout << "Matching" << endl;
      for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
      cout << endl;
    } else {
      cout << "Indset" << endl;
      int cnt = 0;
      for (int i = 0; i < 3 * n; i++) {
        if (used[i] == 0) {
          cout << i + 1 << " ";
          cnt++;
        }
        if (cnt == n) break;
      }
      cout << endl;
    }
  }
}
