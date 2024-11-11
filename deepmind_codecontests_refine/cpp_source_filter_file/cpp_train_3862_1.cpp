#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long MAX = 200005;
bool prime[MAX];
void sieve() {
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (long long p = 2; p * p <= MAX; p++) {
    if (prime[p] == true) {
      for (long long i = p * 2; i <= MAX; i += p) prime[i] = false;
    }
  }
}
long long power(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long t = power(a, b / 2, m);
  t = (t * t) % m;
  if (b & 1) t = (t * a) % m;
  return t;
}
long long modInverse(long long a, long long m) { return power(a, m - 2, m); }
long long __gcd(long long a, long long b) {
  if (b == 0) return a;
  return __gcd(b, a % b);
}
bool cmp(const pair<long long, long long> &l,
         const pair<long long, long long> &r) {
  return l.first < r.first;
}
long long n, q;
vector<vector<long long> > g;
long long visited[MAX];
long long num[MAX];
long long cnt[MAX];
long long k;
long long dfs(long long node) {
  visited[node] = 1;
  num[node] = k;
  k++;
  long long p = 0, flag = 0;
  for (auto i : g[node]) {
    if (!visited[i]) {
      flag = 1;
      p += dfs(i);
    }
  }
  if (flag) {
    cnt[node] = p;
    return 1 + p;
  } else {
    cnt[node] = 0;
    return 1;
  }
}
void solve() {
  cin >> n >> q;
  g.resize(n + 1, vector<long long>());
  long long x;
  for (long long i = 2; i <= n; i++) {
    cin >> x;
    g[i].push_back(x);
    g[x].push_back(i);
  }
  memset(visited, 0, sizeof(visited));
  memset(num, 0, sizeof(num));
  memset(cnt, 0, sizeof(cnt));
  k = 1;
  dfs(1);
  map<long long, long long> m;
  for (long long i = 0; i < MAX; i++) m[num[i]] = i;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    if (cnt[x] < y - 1)
      cout << "-1"
           << "\n";
    else {
      long long w = m[x];
      cout << m[w + y - 1] << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long t;
  t = 1;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
