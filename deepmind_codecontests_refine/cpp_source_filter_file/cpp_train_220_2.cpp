#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0LL) return b;
  if (b == 0LL) return a;
  return gcd(b, a % b);
}
const int N = 251;
const int N1 = 100005;
const int M = 26;
int dp[N][N][N];
int len[3];
int nxt[M][N1], n;
vector<char> r[3];
int solve1(int i0, int i1, int i2) {
  if (i0 < 0 || i1 < 0 || i2 < 0) return n + 1;
  if (dp[i0][i1][i2] != -1) return dp[i0][i1][i2];
  int ans = n + 1;
  int temp;
  temp = solve1(i0 - 1, i1, i2);
  if (temp != n + 1) ans = min(ans, nxt[r[0][i0 - 1] - 'a'][temp]);
  temp = solve1(i0, i1 - 1, i2);
  if (temp != n + 1) ans = min(ans, nxt[r[1][i1 - 1] - 'a'][temp]);
  temp = solve1(i0, i1, i2 - 1);
  if (temp != n + 1) ans = min(ans, nxt[r[2][i2 - 1] - 'a'][temp]);
  dp[i0][i1][i2] = ans;
  return ans;
}
void solve() {
  int q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < 26; i++) nxt[i][n] = n + 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) nxt[j][i] = nxt[j][i + 1];
    nxt[s[i] - 'a'][i] = i + 1;
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < 3; i++) {
    len[i] = 0;
    r[i].clear();
  }
  char op, c;
  int ind, l1, l2;
  while (q--) {
    cin >> op >> ind;
    ind--;
    if (op == '+') {
      cin >> c;
      r[ind].push_back(c);
      len[ind]++;
      if (ind == 0) {
        l1 = len[1];
        l2 = len[2];
      } else if (ind == 1) {
        l1 = len[0];
        l2 = len[2];
      } else {
        l1 = len[0];
        l2 = len[1];
      }
      for (int i = 0; i <= l1; i++)
        for (int j = 0; j <= l2; j++) {
          if (ind == 0)
            dp[len[ind]][i][j] = -1;
          else if (ind == 1)
            dp[i][len[ind]][j] = -1;
          else
            dp[i][j][len[ind]] = -1;
        }
      solve1(len[0], len[1], len[2]);
    } else {
      r[ind].pop_back();
      len[ind]--;
    }
    if (dp[len[0]][len[1]][len[2]] <= n && dp[len[0]][len[1]][len[2]] > 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  clock_t clk = clock();
  int t = 1;
  for (int tests = 1; tests <= t; tests++) {
    solve();
  }
  clk = clock() - clk;
  cerr << "Time Elapsed: " << fixed << setprecision(10)
       << ((long double)clk) / CLOCKS_PER_SEC << "\n";
  return 0;
}
