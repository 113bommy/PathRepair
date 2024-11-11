#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> g(3 * n + 1);
    vector<char> used(3 * n + 1, false);
    vector<long long> match;
    for (long long i = 1; i <= m; i++) {
      long long u, v;
      cin >> u >> v;
      g[u].emplace_back(v, i);
      g[v].emplace_back(u, i);
    }
    for (long long i = 1; i <= 3 * n; i++) {
      if (!used[i]) {
        for (pair<long long, long long> u : g[i]) {
          if (!used[u.first]) {
            used[i] = true;
            used[u.first] = true;
            match.push_back(u.second);
            break;
          }
        }
      }
    }
    if (match.size() >= n) {
      cout << "matching\n";
      for (long long i = 0; i < n; i++) {
        cout << match[i] << ' ';
      }
    } else {
      cout << "indset\n";
      long long t = 0;
      long long f = 1;
      for (long long i = 1; i <= 3 * n && f; i++) {
        if (!used[i] && f) {
          t++;
          cout << i << ' ';
          if (t == n) {
            f = 0;
          }
        }
      }
    }
    cout << '\n';
  }
}
