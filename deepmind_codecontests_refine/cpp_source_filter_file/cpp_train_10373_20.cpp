#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &first, T2 second) {
  if (first > second) first = second;
}
template <typename T1, typename T2>
inline void chkmax(T1 &first, T2 second) {
  if (first < second) first = second;
}
const string FILENAME = "input";
const int p = 1e9 + 7;
int sum(int a, int b) {
  a += b;
  return a >= p ? a - p : a;
}
int mul(long long a, int b) { return a * b % p; }
int powx(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = mul(a, ans);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
int n, m;
bool used[1001];
bool eq[1001][1001];
int dp[1001][1001];
long long ans = 1;
int main() {
  srand(time(0));
  ios::sync_with_stdio(0);
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      eq[i][j] = true;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i < m; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] = sum(mul(j, dp[i - 1][j]), dp[i - 1][j - 1]);
    }
  }
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int L = 0; L < s.size(); ++L) {
      for (int R = L + 1; R < s.size(); ++R) {
        if (s[L] != s[R]) {
          eq[L][R] = false;
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (used[i]) continue;
    int cnt = 0;
    for (int j = i; j < m; ++j) {
      if (eq[i][j]) {
        ++cnt;
        used[j] = true;
      }
    }
    int res = 0;
    for (int j = 0; j <= cnt; ++j) {
      res = sum(res, dp[cnt][j]);
    }
    ans = mul(ans, res);
  }
  cout << ans << endl;
}
