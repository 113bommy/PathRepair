#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool isPalindrome(string s) {
  long long int l = 0;
  long long int h = s.size() - 1;
  while (h > l) {
    if (s[l++] != s[h--]) {
      return false;
    }
  }
  return true;
}
long long int powr(long long int a, long long int b) {
  long long int res = (1.0);
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
vector<long long int> divisors(long long int n) {
  vector<long long int> v;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if ((n / i) == i) {
        v.push_back(i);
      } else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  return v;
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
long long int spf[500004];
long long int mx = 500002;
void pre() {
  for (long long int i = 1; i <= mx; i++) {
    spf[i] = i;
  }
  for (long long int i = 2; i <= mx; i += 2) spf[i] = 2;
  for (long long int i = 3; i * i <= mx; i++) {
    if (spf[i] == i) {
      for (long long int j = i * i; j <= mx; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
}
vector<long long int> getprimefactors(long long int x) {
  vector<long long int> v;
  while (x != 1) {
    v.push_back(spf[x]);
    x = x / spf[x];
  }
  return v;
}
const long long int N = 1e6;
bool pp[N + 2];
void sieve() {
  memset(pp, true, sizeof(pp));
  pp[0] = false;
  pp[1] = true;
  for (long long int i = 2; i <= sqrt(N); i++) {
    if (pp[i]) {
      for (long long int j = i * i; j <= N; j += i) pp[j] = false;
    }
  }
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<long long int> SieveOfEratosthenes(long long int n) {
  bool prime[n + 1];
  vector<long long int> v;
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long int p = 2; p <= n; p++)
    if (prime[p]) v.push_back(p);
  return v;
}
long long int C[2001][2001];
void binomialCoeff(long long int n, long long int k) {
  long long int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
}
long long int nCr(long long int n, long long int r) {
  if (n < r) return 0;
  if (n == r) return 1;
  if (r > n - r) r = n - r;
  long long int ans = 1;
  long long int i;
  for (i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
long long int inv(long long int a) { return powr(a, mod - 2); }
template <typename T>
void make_unique(vector<T> &vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
long long int fact[200006];
const long long int N1 = 200005;
long long int seg[4 * N1];
void build(long long int a[], long long int node, long long int l,
           long long int r) {
  if (l == r) {
    seg[node] = a[l];
  } else {
    long long int m = (l + r) / 2;
    build(a, 2 * node, l, m);
    build(a, 2 * node + 1, m + 1, r);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
  }
}
long long int query(long long int node, long long int ll, long long int rr,
                    long long int l, long long int r) {
  if (l > r) {
    return 0;
  }
  if (ll == l && rr == r) {
    return seg[node];
  }
  long long int m = (ll + rr) / 2;
  return query(2 * node, ll, m, l, min(m, r)) +
         query(2 * node + 1, m + 1, rr, max(l, m + 1), r);
}
long long int factorial(long long int n) {
  long long int res = 1;
  for (long long int i = n; i >= 1; i--) (res *= i) %= mod;
  return (res % mod);
}
unsigned long long power(unsigned long long x, long long int y,
                         long long int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, long long int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, long long int r,
                                 long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
const long long int inf = 1e18;
void toggleChars(char str[]) {
  for (long long int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 'a' - 'A';
    else if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] + 'A' - 'a';
  }
}
long long int add(long long int a, long long int b, long long int mod) {
  long long int res = (a % mod + b % mod) % mod;
  if (res < 0) res += mod;
  return res;
}
vector<long long int> adj[100005];
long long int vis[100005];
void dfs(long long int x, long long int a[]) {
  vis[x] = 1;
  for (auto i : adj[x]) {
    if (vis[i] == 0) {
      dfs(i, a);
    }
  }
}
long long int CEIL(long long int a, long long int b) {
  return (a / b + (a % b != 0));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(C, 0, sizeof(C));
  binomialCoeff(2000, 2000);
  long long int n;
  cin >> n;
  long long int a[n + 1];
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<long long int> v;
  vector<pair<long long int, long long int>> u;
  vector<long long int> vv;
  for (long long int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      v.push_back(i);
    } else if (a[i] < 0) {
      u.push_back({a[i], i});
    } else {
      vv.push_back(i);
    }
  }
  long long int x = u.size();
  sort(u.rbegin(), u.rend());
  if (u.size() % 2 != 0) {
    v.push_back(u[0].second);
    for (long long int i = 1; i < u.size(); i++) {
      vv.push_back(u[i].second);
    }
  } else {
    for (long long int i = 0; i < u.size(); i++) {
      vv.push_back(u[i].second);
    }
  }
  if (v.size() != 0) {
    if (v.size() == 1) {
      if (vv.size() > 1) {
        cout << "2"
             << " " << v[0] << "\n";
      }
    } else {
      for (long long int i = 0; i < v.size() - 1; i++) {
        cout << "1"
             << " " << v[i] << " " << v[i + 1] << "\n";
      }
      if (vv.size() > 1) {
        cout << "2"
             << " " << v[v.size() - 1] << "\n";
      }
    }
  }
  if (vv.size() > 1) {
    for (long long int i = 0; i < vv.size() - 1; i++) {
      cout << "1"
           << " " << vv[i] << " " << vv[i + 1] << "\n";
    }
  }
  return 0;
}
