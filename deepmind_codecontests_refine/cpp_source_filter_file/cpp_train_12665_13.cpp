#include <bits/stdc++.h>
using namespace std;
bool validx(vector<string> &g, long long int i, long long int j,
            long long int k) {
  long long int N = g.size();
  if (j + k >= N) return false;
  for (long long int l = 0; l < k; l++) {
    if (g[i][j + l] == '#') return false;
  }
  return true;
}
bool validy(vector<string> &g, long long int i, long long int j,
            long long int k) {
  long long int N = g.size();
  if (i + k >= N) return false;
  for (long long int l = 0; l < k; l++) {
    if (g[i + l][j] == '#') return false;
  }
  return true;
}
void solve() {
  long long int N, k;
  cin >> N >> k;
  vector<vector<long long int>> cnt(N, vector<long long int>(N, 0));
  vector<string> g(N);
  for (long long int i = 0; i < (N); i++) cin >> g[i];
  ;
  for (long long int i = 0; i < N; i++) {
    for (long long int j = 0; j < N; j++) {
      if (validx(g, i, j, k)) {
        for (long long int l = 0; l < k; l++) {
          cnt[i][j + l]++;
        }
      }
      if (validy(g, i, j, k)) {
        for (long long int l = 0; l < k; l++) {
          cnt[i + l][j]++;
        }
      }
    }
  }
  long long int ans = 0, x = 0, y = 0;
  for (long long int i = 0; i < N; i++) {
    for (long long int j = 0; j < N; j++) {
      if (ans < cnt[i][j]) {
        x = i;
        y = j;
        ans = cnt[i][j];
      }
    }
  }
  cout << x + 1 << " " << y + 1 << endl;
}
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T;
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
