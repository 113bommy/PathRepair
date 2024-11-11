#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1000000007;
const int MAXN = 1000010;
int v[(1 << 20) + 5];
int dp[(1 << 20) + 5][20];
string s;
int set_all;
int n;
int getID(char c) { return c - 'a'; }
int solve(int mask, int i) {
  if (i == n) return v[mask];
  if (dp[mask][i] != -1) return dp[mask][i];
  if (mask & (1 << i))
    return dp[mask][i] = max(solve(mask, i + 1), solve(mask ^ (1 << i), i + 1));
  return dp[mask][i] = solve(mask, i + 1);
}
int main() {
  memset(dp, -1, sizeof(dp));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  n = s.size();
  set_all = (1 << n) - 1;
  for (int i = 0; i < n; i++) {
    int aux = 0;
    int tam = 0;
    for (int j = 0; i + j < n; j++) {
      int id = getID(s[i + j]);
      if (aux & (1 << id)) break;
      aux |= (1 << id);
      tam++;
      v[aux] = tam;
    }
  }
  int ans = 0;
  for (int i = 1; i < (1 << 20); i++)
    ans = max(ans, v[i] + solve(set_all ^ i, 0));
  cout << ans << '\n';
  return 0;
}
