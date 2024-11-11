#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 1005, MOD = 1e9 + 7;
int n, k, par[N][N * 2];
char ct[256], dp[N][N * 2], prv[N][N * 2];
string s, ans;
inline void upd(int ni, int nj, int j, char ch) {
  dp[ni][nj] = 1, par[ni][nj] = j, prv[ni][nj] = ch;
}
bool get() {
  ans = "";
  for (int i = 0; i < n; ++i) {
    fill(dp[i], dp[i] + N, 0);
    fill(par[i], par[i] + N, -1);
  }
  ct['L'] = -1, ct['W'] = 1;
  if (s.back() == 'L') swap(ct['L'], ct['W']);
  dp[0][N] = 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = N - k + 1; j < N + k; ++j) {
      if (!dp[i][j]) continue;
      if (s[i] != '?') {
        if (j + ct[s[i]] > 0 && j + ct[s[i]] < 2 * N)
          upd(i + 1, j + ct[s[i]], j, s[i]);
        continue;
        ;
      }
      upd(i + 1, j, j, 'D');
      if (j + ct['W'] > 0 && j + ct['W'] < 2 * N)
        upd(i + 1, j + ct['W'], j, 'W');
      if (j + ct['L'] > 0 && j + ct['L'] < 2 * N)
        upd(i + 1, j + ct['L'], j, 'L');
    }
  }
  if (dp[n - 1][N + k - 1]) {
    int i = n - 1, j = N + k - 1;
    while (i != 0) {
      ans += prv[i][j];
      j = par[i--][j];
    }
    reverse(ans.begin(), ans.end());
    ans += s.back();
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  cin >> s;
  if (s.back() == 'D') {
    cout << "NO" << '\n';
    return 0;
  }
  bool ok = 0;
  if (s.back() == '?') {
    s.back() = 'W';
    if (!get()) {
      s.back() = 'L';
      ok = get();
    } else {
      ok = 1;
    }
  } else {
    ok = get();
  }
  if (!ok) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << ans << '\n';
  return 0;
}
