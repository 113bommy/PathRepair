#include <bits/stdc++.h>
using namespace std;
char A[105][105];
int dist[105][105];
int P[1000006];
int X[1000006], pre[1000006];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> A[i] + 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (i != j) {
        if (A[i][j] == '0')
          dist[i][j] = 1e9;
        else
          dist[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      for (int k = 1; k <= N; ++k) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
  int M;
  cin >> M;
  for (int i = 1; i <= M; ++i) cin >> P[i];
  for (int i = 1; i <= M; ++i) {
    int l = 0, r = i - 1;
    while (l < r) {
      int m = l + r >> 1;
      if (dist[P[m]][P[i]] == i - m)
        r = m;
      else
        l = m + 1;
    }
    X[i] = X[l] + 1;
    pre[i] = l;
  }
  cout << X[M] << '\n';
  vector<int> ans;
  for (int i = M; i; i = pre[i]) ans.push_back(P[i]);
  reverse(ans.begin(), ans.end());
  for (auto i : ans) cout << i << ' ';
  return 0;
}
