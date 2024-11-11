#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
inline void base() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(6);
}
const int N = 1e5;
const int TK = 300;
int lastPos[TK + 1][N + 5];
int A[N + 5];
int B[N + 5];
vector<int> pos[N + 5];
int main() {
  base();
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  for (int i = 1; i <= m; ++i) cin >> B[i], pos[B[i]].push_back(i);
  long long ans = 0;
  int mxTk = s / e;
  for (int i = 1; i <= n; ++i) {
    if (pos[A[i]].size() == 0)
      lastPos[1][i] = 1e9;
    else {
      lastPos[1][i] = pos[A[i]][0];
      long long cost = e + i + lastPos[1][i];
      if (cost <= s) ans = i;
    }
  }
  for (int i = 2; i <= mxTk; ++i) {
    int mini = 1e9;
    for (int j = 1; j <= n; ++j) {
      int l = 0, r = pos[A[j]].size();
      while (l < r) {
        int m = (l + r) / 2;
        if (pos[A[j]][m] > mini)
          r = m;
        else
          l = m + 1;
      }
      if (l == (int)pos[A[j]].size())
        lastPos[i][j] = 1e9;
      else {
        lastPos[i][j] = pos[A[j]][l];
        long long cost = j + lastPos[i][j] + i * e;
        if (cost <= s) ans = i;
      }
      mini = min(mini, lastPos[i - 1][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
