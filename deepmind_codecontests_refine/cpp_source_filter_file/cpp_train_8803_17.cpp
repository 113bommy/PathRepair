#include <bits/stdc++.h>
using namespace std;
const long long DLT = 1e9 + 7;
const int maxn = 5010;
int n;
long long C[maxn][maxn], dp[2][maxn], ps[maxn], last[256];
string s, t;
long long mod(long long x) {
  while (x < 0) x += DLT;
  while (x >= DLT) x -= DLT;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < maxn; ++i) {
    for (int j = 0; j < maxn; ++j) {
      if (i == j)
        C[i][j] = 1;
      else if (!i)
        C[i][j] = 0;
      else if (!j)
        C[i][j] = 1;
      else
        C[i][j] = mod(C[i - 1][j] + C[i - 1][j - 1]);
    }
  }
  cin >> n >> s;
  t = s[0];
  for (int i = 1; i < n; ++i)
    if (s[i] != s[i - 1]) t += s[i];
  n = t.size();
  long long ans = 0, tmp = 0;
  for (char i = 'a'; i <= 'z'; ++i) last[i] = 0;
  for (int i = 0; i < n; ++i) {
    if (last[t[i]])
      dp[1][i] = 0;
    else {
      dp[1][i] = 1;
      last[t[i]] = 1;
    }
    tmp = mod(tmp + dp[1][i]);
  }
  ans = mod(ans + tmp);
  for (int k = 2; k <= n; ++k) {
    ps[0] = 0;
    tmp = 0;
    for (char i = 'a'; i <= 'z'; ++i) last[i] = -1;
    for (int i = 0; i < n; ++i) {
      dp[k & 1][i] = mod(ps[i] - ps[last[s[i]] + 1]);
      ps[i + 1] = mod(ps[i] + dp[(k - 1) & 1][i]);
      last[s[i]] = i;
      tmp = mod(tmp + dp[k & 1][i]);
    }
    ans = (ans + C[s.size() - 1][k - 1] * tmp) % DLT;
  }
  cout << ans << endl;
  return 0;
}
