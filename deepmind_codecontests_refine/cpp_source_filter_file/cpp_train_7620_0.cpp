#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long exp(long long x, long long n, long long mod) {
  long long result = 1;
  while (n) {
    if (n & 1) result = (result * x) % mod;
    x = (x * x) % mod;
    n = n >> 1;
  }
  return result;
}
int n;
const int INF = 1e9;
void bfs(vector<int> a, vector<int> b, int ans[], vector<int> v[]) {
  vector<int> dist(n, INF);
  queue<int> q;
  for (auto x : a) {
    dist[x] = 0;
    q.push(x);
  }
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (auto x : v[t]) {
      if (dist[x] == INF) {
        dist[x] = dist[t] + 1;
        q.push(x);
      }
    }
  }
  for (auto x : b) {
    if (dist[x] != INF) ans[x] = dist[x];
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int a[n];
  vector<int> odd, even;
  vector<int> v[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] & 1)
      odd.push_back(i);
    else
      even.push_back(i);
    if (i - a[i] >= 0) v[i - a[i]].push_back(i);
    if (i + a[i] < n) v[i + a[i]].push_back(i);
  }
  int ans[n];
  memset(ans, -1, sizeof(ans));
  bfs(even, odd, ans, v);
  bfs(odd, even, ans, v);
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
  return 0;
}
