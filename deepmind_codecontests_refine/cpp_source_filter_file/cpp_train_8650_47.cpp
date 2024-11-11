#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 107;
int cnt[N];
int c[N][N * N];
int dp[N][N * N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  int diff = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
    cnt[x]++;
    if (cnt[x] == 1) {
      diff++;
    }
  }
  if (diff <= 2) {
    cout << n << '\n';
    return 0;
  }
  c[0][0] = 1;
  for (int i = 1; i < N; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }
  dp[0][0] = 1;
  for (int x : a) {
    for (int k = n; k >= 1; k--) {
      for (int j = N - 1; j >= x; j--) {
        dp[k][j] += dp[k - 1][j - x];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      int need = i * j;
      if (dp[j][need] == c[cnt[i]][j]) {
        ans = max(ans, j);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
