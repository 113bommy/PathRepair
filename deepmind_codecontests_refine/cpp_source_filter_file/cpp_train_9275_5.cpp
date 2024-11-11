#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long fact[100001];
vector<long long> vec[100001];
long long vis[100001], win[100001], flag[100001];
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return res;
}
long long nCr(long long n, long long r) {
  if (r > n)
    return 0;
  else if (r < 0)
    return 0;
  else if (r == 0 || r == n)
    return 1;
  long long ans = fact[n];
  ans = (ans * power(fact[n - r], mod - 2)) % mod;
  ans = (ans * power(fact[r], mod - 2)) % mod;
  return ans;
}
void dfs(long long x) {
  vis[x] = 1;
  for (long long i = 0; i < vec[x].size(); i++) {
    long long node = vec[x][i];
    if (vis[node] == -1) dfs(node);
    if (win[node] == 0) flag[x] = 1;
  }
  if (flag[x] == 1) win[x] = 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i < n; i++) {
    for (long long j = i; j > 0; j -= a[i]) {
      if (a[j] > a[i]) vec[a[i]].push_back(a[j]);
    }
    for (long long j = i; j <= n; j += a[i]) {
      if (a[j] > a[i]) vec[a[i]].push_back(a[j]);
    }
  }
  for (long long i = 1; i <= n; i++) {
    vis[i] = -1;
    win[i] = 0;
    flag[i] = 0;
  }
  dfs(1);
  string s;
  for (long long i = 1; i <= n; i++) {
    if (win[a[i]] == 1)
      s += 'A';
    else
      s += 'B';
  }
  cout << s << endl;
  for (long long i = 1; i <= n; i++) vec[i].clear();
  return 0;
}
