#include <bits/stdc++.h>
#pragma GCC_OPTIMIZE("ofast")
using namespace std;
long long INF = 1000000000LL;
signed main() {
  long long n;
  cin >> n;
  vector<vector<long long>> d(n, vector<long long>(n, INF));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == 0) {
        d[i][j] = INF;
      } else {
        d[i][j] = 1;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    d[i][i] = 0;
  }
  for (long long k = 0; k < n; k++) {
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  long long m;
  cin >> m;
  vector<long long> p(m);
  for (long long i = 0; i < m; i++) {
    cin >> p[i];
    p[i]--;
  }
  vector<long long> ans;
  ans.push_back(p[0]);
  long long now = p[0];
  long long last = 0;
  for (long long i = 1; i < m; i++) {
    if (d[now][p[i]] != i - last) {
      ans.push_back(p[i - 1]);
      now = p[i - 1];
      last = i - 1;
    }
  }
  if (ans.back() != p.back()) {
    ans.push_back(p.back());
  }
  cout << ans.size() << "\n";
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
}
