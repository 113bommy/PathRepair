#include <bits/stdc++.h>
using namespace std;
const long long N = 101000;
long long n;
long long segtree[2 * N];
vector<long long> g[N];
vector<long long> dp(N);
vector<long long> dp2(N);
long long inv(long long a, long long m = 1000000007) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long pow(long long a, long long b) {
  a %= 1000000007;
  long long res = 1;
  while (b) {
    if (a % 2) res *= a, res %= 1000000007;
    a *= a;
    a %= 1000000007;
    b >> 1;
  }
  return res % 1000000007;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void printv(vector<long long> v, long long n = 0) {
  if (!n) n = v.size();
  for (long long x : v) {
    cout << x << " ";
  }
  cout << endl;
}
void printm(map<long long, long long> m, long long n = 0) {
  if (!n) n = m.size();
  for (auto x : m) {
    cout << x.first << " " << x.second << endl;
  }
  cout << endl;
}
void printarr(long long arr[], long long n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}
void ipgraph(long long m) {
  long long a, b;
  for (long long i = 0; i < m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
}
void dfs(long long root, long long parent = 0) {
  long long ans = 0;
  for (long long x : g[root]) {
    if (x == parent) continue;
    dfs(x, root);
    ans += dp[x];
    dp2[x] = root;
  }
  dp[root] = 1 + ans;
}
void bfs(long long root) {
  vector<long long> visit(N);
  visit[root]++;
  queue<long long> q;
  q.push(root);
  while (!q.empty()) {
    long long x = q.front();
    q.pop();
    for (auto c : g[x]) {
      if (!visit[c]) {
        visit[c]++;
        q.push(c);
      }
    }
  }
}
void clr(int n) {
  for (long long i = 0; i < n; i++) {
    g[i].clear();
    dp[i] = 0;
    dp2[i] = 0;
  }
}
int main() {
  long long t, i, j, k, q, m;
  cin >> n >> m >> k;
  long long a, b;
  long long ans = INT_MAX;
  for (long long i = 0; i < k; i++) {
    cin >> a >> b;
    ans = min(ans, min(abs(n - a), min(abs(m - b), min(a, b))));
  }
  if (ans <= 5)
    cout << "YES\n";
  else {
    cout << "NO\n";
  }
}
