#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
const ll MODBASE = 1000000007LL;
const int MAXN = 55;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;
int t, n, lab[MAXN], degIn[MAXN];
ll k, dp[MAXN], f[MAXN];
ll F(int u) {
  if (u <= 1) return 1;
  if (u > 20) return 2e18;
  if (f[u] != -1) return f[u];
  ll res = 1;
  for (int i = (1); i <= (u - 2); i++) res *= i;
  return f[u] = res;
}
ll DP(int u) {
  if (u <= 20) return dp[u];
  return 2e18;
}
bool canConnect(int u, int v) {
  if (u == v) return false;
  if (degIn[v]) return false;
  if (lab[u] == lab[v]) return false;
  return true;
}
bool connect(int u, int v, int l, int r) {
  if (!canConnect(u, v)) return false;
  int p = lab[u];
  for (int i = (l); i <= (r); i++)
    if (lab[i] == p) lab[u] = lab[v];
  degIn[v] = true;
  return true;
}
void build(int st, int n, ll x, ll &remain) {
  int en = st + n - 1;
  cout << en << ' ';
  if (n == 1) return;
  for (int i = (st); i <= (en); i++) {
    lab[i] = i;
    degIn[i] = false;
  }
  connect(st, en, st, en);
  int numComp = n - 1;
  for (int i = (st + 1); i <= (en); i++)
    for (int j = (st); j <= (en); j++) {
      if (i == en) {
        if (!degIn[j]) {
          cout << j << ' ';
          break;
        }
        continue;
      }
      if (canConnect(i, j)) {
        if (x * F(numComp) < remain) {
          remain -= x * F(numComp);
          continue;
        }
        numComp--;
        connect(i, j, st, en);
        cout << j << ' ';
        break;
      }
    }
}
void solve(int n, ll remain, int st) {
  if (n <= 0) return;
  if (n == 1) {
    cout << st << ' ';
    return;
  }
  for (int i = (1); i <= (n); i++)
    if (F(i) * DP(n - i) < remain)
      remain -= F(i) * DP(n - i);
    else {
      build(st, i, DP(n - i), remain);
      solve(n - i, remain, st + i);
      break;
    }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  for (int i = (1); i <= (50); i++) f[i] = dp[i] = -1;
  dp[0] = 1;
  dp[1] = 1;
  for (int i = (2); i <= (20); i++) {
    dp[i] = 0;
    for (int j = (1); j <= (i); j++) dp[i] += F(j) * dp[i - j];
  }
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (n <= 20 && k > DP(n)) {
      cout << -1 << "\n";
      continue;
    }
    solve(n, k, 1);
    cout << "\n";
  }
  return 0;
}
