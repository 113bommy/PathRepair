#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isperfect(long long n) {
  long long y = sqrt(n);
  if (n % y == 0 && y * y == n) return true;
  return false;
}
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
long long powi(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a);
    b = b >> 1;
    a = (a * a);
  }
  return ans;
}
bool isprime(long long n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
bool prime[10000000];
void seive() {
  prime[1] = true;
  for (int i = 2; i * i < 10000000; i++) {
    if (prime[i]) continue;
    for (int j = i * i; j < 10000000; j += i) {
      prime[j] = true;
    }
  }
}
long long dp[200007][2];
vector<long long int> a(200007);
int n;
bool vis[200007][2];
long long dfs(long long x, long long y, int sn) {
  if (x <= 0 || x > n) return 0;
  long long ans = dp[x][sn];
  if (ans != -1) return ans;
  ans = -1e18;
  if (vis[x][sn]) return ans;
  vis[x][sn] = 1;
  if (!sn) {
    ans = a[x] + dfs(a[x] + x, y + a[x], 1 - sn);
  } else {
    ans = a[x] + dfs(x - a[x], y - a[x], 1 - sn);
  }
  vis[x][sn] = 0;
  dp[x][sn] = ans;
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 2; i <= n; i++) cin >> a[i];
  long long ans = -1;
  for (int i = 1; i < n; i++) {
    ans = i + dfs(i + 1, 0, 1);
    if (ans < 0) ans = -1;
    cout << ans << endl;
  }
}
