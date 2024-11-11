#include <bits/stdc++.h>
using namespace std;
long long int dxk[] = {0, 0, 1, -1, 1, 1, -1, -1};
long long int dyk[] = {1, -1, 0, 0, 1, -1, 1, -1};
long long int ll_max(long long int a, long long int b, long long int c) {
  return max(a, max(b, c));
}
int int_max(int a, int b, int c) { return max(a, max(b, c)); }
long long int ll_min(long long int a, long long int b, long long int c) {
  return min(a, min(b, c));
}
int int_min(int a, int b, int c) { return min(a, min(b, c)); }
long long int max(int a, long long int b) { return max((long long int)a, b); }
long long int min(int a, long long int b) { return min((long long int)a, b); }
long long int min(long long int a, int b) { return min(a, (long long int)b); }
long long int max(long long int a, int b) { return max(a, (long long int)b); }
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, 0};
long long int power(long long int a, long long int b) {
  if (a == 1) return 1;
  if (b == 0) return 1;
  long long int c = power(a, b / 2);
  long long int res = 1;
  if (b % 2) {
    res = (c * c) % 1000000007;
    res *= a;
    res %= 1000000007;
  } else
    res = ((c * c) % 1000000007);
  return res;
}
long long int modInv(long long int a) {
  return power(a, 1000000007 - 2) % 1000000007;
}
long long int fact[1], inv[1];
void factorial(long long int n) {
  fact[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= 1000000007;
  }
}
void InvFactorial(long long int n) {
  inv[0] = 1;
  for (long long int i = 1; i <= n; i++) inv[i] = modInv(fact[i]);
}
long long int ncr(long long int n, long long int r) {
  if (n < r || n < 0 || r < 0) return 0;
  long long int b = inv[n - r];
  long long int c = inv[r];
  long long int a = fact[n] * b;
  a %= 1000000007;
  a *= c;
  a %= 1000000007;
  return a;
}
int n, m;
int a[1000][1000];
bool visited[1001][1001];
long long int dp[1001][1001];
long long int dfs(int i, int j) {
  if (visited[i][j] && dp[i][j] == -1) {
    dp[i][j] = 10000000000000000;
    return 10000000000000000;
  }
  if (visited[i][j]) return dp[i][j];
  visited[i][j] = 1;
  long long int maxx = 0;
  for (long long int k = 0; k < 4; k++) {
    int h = i + dx[k];
    int h1 = j + dy[k];
    if (h < 0 || h1 < 0 || h == n || h1 == m) continue;
    int l = (a[i][j] + 1) % 4;
    if (a[h][h1] == l) maxx = max(maxx, dfs(h, h1));
  }
  if (a[i][j] == 3) maxx++;
  dp[i][j] = maxx;
  return maxx;
}
void solve(int countu) {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  vector<pair<int, int> > v;
  for (long long int i = 0; i < n; i++) {
    char s[1000];
    scanf("%s", &s);
    for (long long int j = 0; j < m; j++) {
      if (s[j] == 'D') {
        v.push_back({i, j});
        a[i][j] = 0;
      } else if (s[j] == 'I')
        a[i][j] = 1;
      else if (s[j] == 'M')
        a[i][j] = 2;
      else
        a[i][j] = 3;
    }
  }
  if (v.size() == 0) {
    cout << "Poor Dima!\n";
    return;
  }
  long long int maxx = 0;
  for (long long int k = 0; k < v.size(); k++) {
    int i = v[k].first;
    int j = v[k].second;
    maxx = max(maxx, dfs(i, j));
    if (maxx > 100000000) {
      cout << "Poor Inna!\n";
      return;
    }
  }
  if (maxx == 0) {
    cout << "Poor Dima!\n";
    return;
  }
  cout << maxx << '\n';
}
int main() {
  int t = 1;
  int countu = 1;
  while (t--) {
    solve(countu);
    countu++;
  }
}
