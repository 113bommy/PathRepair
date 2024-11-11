#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long MAX = 1e18 + 1;
const double pi = 3.1415926535897932384626433832;
const long long M = 1e9 + 7;
long long bis(long long a[], long long l, long long r, long long x) {
  while (l <= r) {
    long long m = l + (r - l) / 2;
    if (a[m] == x) return m;
    if (a[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
long long gcd(long long x, long long y) {
  if (x == 0)
    return y;
  else
    return gcd(y % x, x);
}
long long lcm(long long x, long long y) { return (x * y) / gcd(x, y); }
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
bool pdrome(string s) {
  long long n = s.length();
  for (long long i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}
string need(string s) {
  string a = s;
  reverse(a.begin(), a.end());
  a = s + '?' + a;
  long long n = a.size();
  long long pref[n];
  memset(pref, 0, sizeof(pref));
  for (long long i = 1; i < n + 1; i++) {
    long long len = pref[i - 1];
    while (len > 0 && a[len] != a[i]) len = pref[len - 1];
    if (a[i] == a[len]) len++;
    pref[i] = len;
  }
  return a.substr(0, pref[n - 1]);
}
long long mindig(long long x) {
  long long ans = 9;
  long long t = x;
  while (x) {
    ans = min(ans, x % 10);
    x /= 10;
  }
  x = t;
  return ans;
}
long long maxdig(long long x) {
  long long ans = 0;
  long long t = x;
  while (x) {
    ans = max(ans, x % 10);
    x /= 10;
  }
  x = t;
  return ans;
}
long long modpow(long long x, long long n, long long M) {
  if (n == 0) return 1 % M;
  long long u = modpow(x, n / 2, M);
  u = (u * u) % M;
  if (n % 2 == 1) u = (u * x) % M;
  return u;
}
long long sumdigits(long long a) {
  long long result = 0;
  while (a > 0) {
    result += a % 10;
    a /= 10;
  }
  return result;
}
long long digits(long long n) { return floor(log10(n) + 1); }
const long long Node = 1e5 + 7;
vector<long long> adj[Node];
bool vis[Node] = {false};
void addedge(long long u, long long v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void bfs(long long u) {
  vis[u] = true;
  list<long long> q;
  q.push_back(u);
  while (!q.empty()) {
    q.pop_front();
    for (auto x : adj[u]) {
      if (!vis[x]) {
        vis[x] = true;
        q.push_back(x);
      }
    }
  }
}
void dfs(long long u) {
  vis[u] = true;
  cout << u << " ";
  for (auto x : adj[u]) {
    if (!vis[x]) {
      dfs(x);
    }
  }
}
long long con1(string s) {
  long long res = 0;
  stringstream geek(s);
  geek >> res;
  return res;
}
string con2(long long num) {
  string stri = to_string(num);
  return stri;
}
long long countbits(long long k) {
  long long cnt = log2(k);
  return cnt;
}
bool check(string s, long long k1, long long j) {
  for (long long i = j; i < k1 / 2 + j; i++) {
    if (s[i] != s[i + k1 / 2]) return false;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 2;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = n; j >= i + 2; j--) {
      long long k = j - i;
      if (k % 2 == 0) {
        if (check(s, k, i) == true) {
          ans = max(ans, k);
        }
      }
    }
  }
  ans = n - ((ans) / 2 - 1);
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
