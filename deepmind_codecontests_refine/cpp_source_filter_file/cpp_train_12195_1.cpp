#include <bits/stdc++.h>
using namespace std;
const long long hell = 1e9 + 7;
long long inf = 1e18;
const long long N = 1e5 + 9;
bool prime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long power(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long n;
vector<long long> adj[N];
long long a[N];
long long colr[N];
long long colb[N];
void dfs(long long i, long long par) {
  if (a[i] == 2)
    colb[i]++;
  else if (a[i] == 1)
    colr[i]++;
  for (auto x : adj[i]) {
    if (x == par) continue;
    dfs(x, i);
    colr[i] += colr[x];
    colb[i] += colb[x];
  }
}
long long ct = 0;
void dfs1(long long i, long long par) {
  for (auto x : adj[i]) {
    if (x == par) continue;
    long long r1 = colr[1];
    long long b1 = colb[1];
    long long r2 = colr[x];
    long long b2 = colb[x];
    if (((r1 - r2) > 0 and (b1 - b2 > 0)) or (r2 > 0 and b2 > 0)) ct++;
    dfs1(x, i);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 0; i < n - 1; i++) {
      long long x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    dfs(1, 0);
    dfs1(1, 0);
    cout << n - 1 - ct;
  }
  return 0;
}
