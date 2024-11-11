#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> A(n, vector<long long>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  vector<vector<long long>> g(n * m);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      A[i][j] = 15 - A[i][j];
      if (i != 0) {
        if (A[i][j] >= 8) {
          A[i][j] -= 8;
          g[i * m + j].push_back((i - 1) * m + j);
          g[(i - 1) * m + j].push_back(i * m + j);
        }
      }
      if (j != m - 1) {
        if (A[i][j] >= 4) {
          A[i][j] -= 4;
          g[i * m + j].push_back(i * m + j + 1);
          g[i * m + j + 1].push_back(i * m + j);
        }
      }
      if (i != n - 1) {
        if (A[i][j] >= 2) {
          A[i][j] -= 2;
          g[i * m + j].push_back((i + 1) * m + j);
          g[(i + 1) * m + j].push_back(i * m + j);
        }
      }
      if (j != 0) {
        if (A[i][j] >= 1) {
          A[i][j] -= 1;
          g[i * m + j].push_back(i * m + j - 1);
          g[i * m + j - 1].push_back(i * m + j);
        }
      }
    }
  }
  vector<bool> used(n * m, false);
  vector<long long> ans;
  for (long long v = 0; v < n * m; v++) {
    if (!used[v]) {
      used[v] = true;
      long long kek = 1;
      vector<long long> st = {v};
      while (!st.empty()) {
        long long u = st.back();
        st.pop_back();
        for (auto uu : g[u]) {
          if (!used[uu]) {
            used[uu] = true;
            st.push_back(uu);
            kek++;
          }
        }
      }
      ans.push_back(kek);
    }
  }
  sort(ans.rbegin(), ans.rend());
  for (auto x : ans) {
    cout << x << ' ';
  }
}
