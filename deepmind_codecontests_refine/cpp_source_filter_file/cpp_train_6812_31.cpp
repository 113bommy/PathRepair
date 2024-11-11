#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
const long long Mod = 1e5 + 7;
const int N = 105;
int n, m, k;
int dp[N][N][12], A[N][N];
char dir[N][N][12];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  char z;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> z;
      A[i][j] = z - '0';
      if (i == n) 1;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int l = 0; l < 12; l++) dp[i][j][l] = -Mod;
    }
  }
  for (int i = 1; i <= m; i++) {
    dp[n][i][A[n][i] % (k + 1)] = A[n][i];
    1;
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      for (int r = 0; r <= k; r++) {
        int prev = (20 * (k + 1) + r - A[i][j]) % (k + 1);
        1;
        int a = -Mod, b = -Mod;
        if (j >= 2) a = dp[i + 1][j - 1][prev] + A[i][j];
        if (j < n) b = dp[i + 1][j + 1][prev] + A[i][j];
        1;
        dp[i][j][r] = max(a, b);
        if (a > b)
          dir[i][j][r] = 'L';
        else
          dir[i][j][r] = 'R';
        1;
      }
    }
  }
  int ans = -1, idx = 0;
  for (int i = 1; i <= m; i++) {
    ans = max(ans, dp[1][i][0]);
    if (dp[1][i][0] == ans) idx = i;
  }
  cout << ans << endl;
  if (ans != -1) {
    int i = 1, j = idx, r = 0;
    vector<char> v;
    while (i != n) {
      v.push_back(dir[i][j][r]);
      ans -= A[i][j];
      if (dir[i][j][r] == 'R')
        j++;
      else
        j--;
      i++;
      r = (ans) % (k + 1);
    }
    cout << j << endl;
    reverse((v).begin(), (v).end());
    for (auto it : v) {
      if (it == 'R')
        cout << 'L';
      else
        cout << 'R';
    }
  }
  return 0;
}
