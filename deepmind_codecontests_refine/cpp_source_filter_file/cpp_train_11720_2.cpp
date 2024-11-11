#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long double e = exp(1);
const long double pi = acos(-1.0);
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long binpows(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const long long mod = 1e9 + 7;
const long long N = 1e5 + 6;
long long n;
vector<long long> adj[N];
vector<long long> col;
bool dfs(long long pos, long long pai) {
  if (pos == pai) {
    bool achou = true;
    for (long long i : adj[pos]) {
      achou &= dfs(i, pos);
    }
    return achou;
  }
  bool achou = true;
  for (long long i : adj[pos]) {
    if (i != pai and col[i] != col[pos]) {
      return false;
    } else if (i != pai) {
      achou &= dfs(i, pos);
    }
  }
  return true;
}
void solve() {
  cin >> n;
  col.resize(n);
  for (long long i = 0; i < (n - 1); i++) {
    long long a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (long long i = 0; i < (n); i++) cin >> col[i + 1];
  for (long long i = 1; i <= n; i++) {
    for (auto it : adj[i]) {
      if (col[i] != col[it]) {
        if (dfs(i, i)) {
          cout << "YES" << endl;
          cout << i << endl;
        } else if (dfs(it, it)) {
          cout << "YES" << endl;
          cout << it << endl;
        } else {
          cout << "NO" << endl;
        }
        return;
      }
    }
  }
  cout << "YES" << endl;
  cout << 1 << endl;
}
signed main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long t = 1;
  while (t--) {
    solve();
  }
}
