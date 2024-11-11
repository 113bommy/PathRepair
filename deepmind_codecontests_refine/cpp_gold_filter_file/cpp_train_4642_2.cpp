#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, m;
vector<int> v[N];
vector<int> nxt[N + 3];
bool ban[N];
int phi[N + 1];
int dp[N];
int to[N];
int gcd(int x, int y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
int deg(long long x, int y, long long p) {
  if (y == 0) return 1;
  long long res = deg(x, y / 2, p);
  res = (res * res) % p;
  if (y % 2 == 1) res = (res * x) % p;
  return res;
}
int back(int x, int p) { return deg(x, phi[p] - 1, p); }
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  fill(ban, ban + m, false);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ban[x] = true;
  }
  if (n == m) {
    cout << "0\n";
    return 0;
  }
  if (m == 1) {
    if (n == 1)
      cout << "0\n";
    else
      cout << "1\n0\n";
    return 0;
  }
  for (int i = 1; i < m; i++) {
    if (!ban[i]) v[gcd(i, m)].push_back(i);
  }
  if (!ban[0]) v[0].push_back(0);
  for (int i = 1; i <= m; i++) phi[i] = i;
  for (int i = 1; i < m; i++) {
    for (int j = 2 * i; j <= m; j += i) phi[j] -= phi[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < (int)(v[i].size()) - 1; j++) {
      int d = gcd(v[i][j], m);
      int x = v[i][j] / d;
      int y = v[i][j + 1] / d;
      nxt[i].push_back(((long long)y * back(x, m / d)) % m);
    }
  }
  for (int i = 0; i < m; i++) dp[i] = v[i].size();
  fill(to, to + m, -1);
  if (v[0].size() > 0) dp[0] = 1;
  for (int i = m - 1; i >= 1; i--) {
    for (int j = 2 * i; j < m; j += i) {
      if (v[j].size() != 0 && dp[j] + v[i].size() > dp[i]) {
        dp[i] = dp[j] + v[i].size();
        to[i] = j;
      }
    }
    if (v[0].size() != 0 && dp[0] + v[i].size() > dp[i]) {
      dp[i] = dp[0] + v[i].size();
      to[i] = 0;
    }
  }
  int ans = 0;
  int cur = -1;
  for (int i = 0; i < m; i++) {
    if (dp[i] > ans) {
      ans = dp[i];
      cur = i;
    }
  }
  cout << ans << endl;
  cout << v[cur][0] << " ";
  while (cur != -1) {
    for (int i = 0; i < nxt[cur].size(); i++) cout << nxt[cur][i] << " ";
    if (to[cur] == -1) break;
    if (to[cur] == 0) {
      cout << "0 ";
      break;
    }
    long long x = v[cur][v[cur].size() - 1];
    long long d = gcd(cur, m);
    cout << ((((long long)v[to[cur]][0] / d * back(x / d, m / d)) % m)) % m
         << " ";
    cur = to[cur];
  }
  cout << endl;
  return 0;
}
