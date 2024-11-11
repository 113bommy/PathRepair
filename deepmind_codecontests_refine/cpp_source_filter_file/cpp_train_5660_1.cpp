#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, INF = 1e18, N = 3e5 + 5;
bool vowel(char che) {
  if (che == 'A' || che == 'E' || che == 'I' || che == 'O' || che == 'U' ||
      che == 'Y') {
    return true;
  } else {
    return false;
  }
}
long long pw(long long a, long long b) {
  int64_t ans = 1;
  while (b) {
    if (b % 2 == 1) {
      ans = 1ll * ans * a;
      ans %= MOD;
    }
    b /= 2;
    a = 1ll * a * a % MOD;
    a %= MOD;
  }
  return ans % MOD;
}
long long ceil_div(long long a, long long b) { return (a + b - 1) / b; }
bool mark, h;
char o;
vector<long long> vt, jav, vs;
pair<long long, long long> p;
string s;
queue<long long> q;
stack<char> st;
int64_t a[N], b[N], c[N], dis, t, n, m, ans, k, f, pd[N], sum;
int64_t pew[200][2], dp[200][200], ent[200][200];
void entekhub() {
  for (int i = 0; i <= n; i++) {
    ent[0][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      ent[j][i] = ent[j][i - 1] + ent[j - 1][i - 1] % MOD;
      ent[j][i] %= MOD;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  f = min(n, k);
  long long r = m / n;
  entekhub();
  for (int i = 0; i <= n; i++) {
    pew[i][0] = pw(ent[i][n], r);
    pew[i][1] = pw(ent[i][n], r + 1);
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= f; j++) {
      for (int g = 0; g <= (min((n - i + 1) * n, k) - j); g++) {
        if ((((m - i) / n) + 1) == r)
          t = pew[j][0] % MOD;
        else
          t = pew[j][1] % MOD;
        if (g == 0)
          dp[i][j + g] += t;
        else
          dp[i][j + g] += dp[i + 1][g] * t;
        dp[i][j + g] %= MOD;
      }
    }
  }
  cout << dp[1][k] << endl;
}
