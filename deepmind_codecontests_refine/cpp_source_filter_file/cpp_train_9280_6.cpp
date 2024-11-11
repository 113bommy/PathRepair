#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long MOD = 998244353;
const int MAXN = 2e5 + 100;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long DP[MAXN][3];
vector<int> v[MAXN];
int n;
long long bigmod(long long a, long long b) {
  if (b == 0) return 1;
  long long now = bigmod(a, b / 2);
  now = now * now % MOD;
  if (b % 2) now = now * a % MOD;
  return now;
}
void dfs(int now, int p) {
  if (v[now].size() == 1 && p != -1) {
    DP[now][0] = 1;
    DP[now][1] = 0;
    DP[now][2] = 0;
    return;
  }
  long long tmp1 = 1, tmp0 = 1;
  for (int i = 0; i < v[now].size(); i++) {
    int sek = v[now][i];
    if (sek == p) continue;
    dfs(sek, now);
    tmp1 = tmp1 * (DP[sek][0] + DP[sek][1]) % MOD;
    tmp0 = tmp0 * (2 * DP[sek][0] + DP[sek][1] + DP[sek][2]) % MOD;
  }
  DP[now][1] = tmp1;
  long long tmp3 = 0;
  for (int i = 0; i < v[now].size(); i++) {
    int sek = v[now][i];
    if (sek == p) continue;
    tmp3 = (tmp3 + (DP[sek][2] + DP[sek][0]) * DP[now][1] % MOD *
                       bigmod((DP[sek][0] + DP[sek][1]) % MOD, MOD - 2) % MOD) %
           MOD;
  }
  DP[now][2] = tmp3;
  DP[now][0] = (tmp0 - DP[now][2] - DP[now][1]) % MOD + MOD;
  DP[now][0] %= MOD;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int x;
    cin >> x;
    x--;
    v[x].push_back(i);
    v[i].push_back(x);
  }
  dfs(0, -1);
  cout << DP[0][0] + DP[0][1] << '\n';
}
