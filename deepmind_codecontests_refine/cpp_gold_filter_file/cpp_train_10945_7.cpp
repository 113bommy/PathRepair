#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int ispalindrome(string ss) {
  long long int n = ss.size();
  for (long long int i = 0; i < (n + 1) / 2; i++) {
    if (ss[i] != ss[n - i - 1]) return 0;
  }
  return 1;
}
long long int mod = 1e9 + 7;
long long int ksm(long long int a, long long int b) {
  long long int S = 1;
  while (b) {
    if (b & 1) S = S * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return S;
}
long long int digit(long long int n) {
  long long int res = 0;
  while (n) {
    res++;
    n = n / 10;
  }
  return res;
}
long long int fact(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i < n + 1; i++) ans = ((ans * i) % mod);
  return ans % mod;
}
long long int isprime(long long int n) {
  if (n == 2 || n == 3) return 1;
  for (long long int i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long int kk = 0;
long long int help(long long int a, long long int b) {
  long long int p = min(a, b / 2) - 1;
  if (p < 0) return 0;
  return p;
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return (temp * temp) % mod;
  else
    return (x * (temp * temp) % mod) % mod;
}
vector<long long int> arr[200010];
long long int vis[200010], dist[200010];
vector<long long int> v;
vector<pair<long long int, long long int>> res;
void bfs(long long int src) {
  queue<long long int> q;
  q.push(src);
  vis[src] = 1;
  while (!q.empty()) {
    long long int cur = q.front();
    q.pop();
    for (int child : arr[cur]) {
      if (vis[child] == 0) {
        q.push(child);
        res.push_back({cur, child});
        vis[child] = 1;
      }
    }
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int mx = 0, maxnode;
  for (long long int i = 0; i < m; i++) {
    long long int a, b;
    cin >> a >> b;
    arr[b].push_back(a);
    arr[a].push_back(b);
  }
  long long int x;
  for (long long int i = 1; i < n + 1; i++) {
    if (arr[i].size() > mx) {
      mx = arr[i].size();
      maxnode = i;
    }
  }
  bfs(maxnode);
  for (long long int i = 0; i < n - 1; i++) {
    cout << res[i].first << " " << res[i].second << endl;
  }
}
int main() {
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
}
