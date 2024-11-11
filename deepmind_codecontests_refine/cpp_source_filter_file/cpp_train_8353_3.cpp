#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 1;
vector<int> sieve(int n) {
  vector<int> prime;
  vector<int> pr(n + 1);
  pr[0] = -1;
  pr[1] = -1;
  for (int i = 2; i < n + 1; ++i) {
    if (pr[i] != -1) {
      pr[i] = 1;
      for (int j = 2 * i; j <= n; j += i) {
        pr[j] = -1;
      }
    }
  }
  for (int i = 1; i < n + 1; ++i) {
    if (pr[i] == 1) {
      prime.push_back(i);
    }
  }
  return prime;
}
vector<int> min_prime_factor(int n) {
  vector<int> min_pf(n + 1);
  for (int i = 2; i < n + 1; ++i) {
    min_pf[i] = 0;
  }
  min_pf[0] = 2;
  min_pf[1] = -1;
  for (int i = 2; i < n + 1; ++i) {
    if (min_pf[i] == 0) {
      for (int j = i; j <= n; j += i) {
        if (min_pf[j] == 0) min_pf[j] = i;
      }
    }
  }
  return min_pf;
}
vector<pair<int, int> > factorise(int n) {
  vector<int> min_pf = min_prime_factor(n);
  vector<pair<int, int> > factors;
  int cnt = 0, fac = 1;
  while (n != 1) {
    cnt = 0;
    fac = min_pf[n];
    while (n % fac == 0) {
      cnt++;
      n /= fac;
    }
    factors.push_back(make_pair(fac, cnt));
  }
  return factors;
}
vector<int> PHI(int n) {
  vector<int> phi(n + 1);
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 2; i < n + 1; ++i) {
    phi[i] = i;
  }
  for (int i = 2; i < n + 1; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] = phi[j] - phi[j] / i;
      }
    }
  }
  return phi;
}
long long int C2(long long int n) {
  long long int ans = max(((n * (n - 1)) / 2), (long long int)0);
  return ans;
}
long long int sq(long long int x) { return x * x; }
long long int BinExp(long long int a, long long int b, long long int m) {
  long long int res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = (res * a) % m;
    b >>= 1;
    a = (a * a) % m;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  if (a < b) swap(a, b);
  return gcd(b, a % b);
}
long long int gcdExtended(long long int a, long long int b, long long int &x,
                          long long int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int g = gcdExtended(b, a % b, x1, y1);
  x = y1;
  y = x1 - ((long long int)(a / b)) * (y1);
  return g;
}
long long int mod_inv(long long int a, long long int m) {
  long long int x, y;
  long long int g = (gcdExtended(a, m, x, y));
  if (g != 1)
    return -1;
  else {
    long long int ans = ((x % m) + m) % m;
    return ans;
  }
}
long long int lcm(long long int a, long long int b) {
  long long int mul = a * b;
  if (a == 0 || b == 0) return 0;
  return (mul / gcd(a, b));
}
bool sortsec(const pair<long long int, long long int> &a,
             const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
bool sortinrev(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.first > b.first);
}
long long int compute_hash(string s) {
  long long int p = 31, m = 1e9 + 9;
  long long int hash = 0, po = 1;
  for (int i = 0; i < s.length(); i++) {
    hash = (hash + (s[i] - 'a' + 1) * po) % m;
    po = (po * p) % m;
  }
  return hash;
}
vector<long long int> LPS(string s) {
  int n = s.length();
  vector<long long int> lps(n);
  for (int i = 1; i < n; i++) {
    int j = lps[i - 1];
    while (j > 0 && lps[j] != lps[i]) {
      j = lps[j - 1];
    }
    if (s[i] == s[j]) ++j;
    lps[i] = j;
  }
  return lps;
}
const int V = 4e5 + 5;
vector<vector<int> > adj(V);
vector<bool> vis(V);
void dfs(int s) {
  vis[s] = 1;
  for (auto i : adj[s]) {
    if (!vis[i]) {
      dfs(i);
    }
  }
}
void solve_g() {
  int x, y;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}
void solve() {
  int t;
  cin >> t;
  for (int p = 0; p < t; p++) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < n; i++) {
      m[s[i]]++;
    }
    vector<int> v;
    for (auto i : m) {
      v.push_back(i.second);
    }
    sort(v.begin(), v.end());
    int ans = v.back();
    vector<int> fact;
    for (int i = 1; i < k + 1; i++) {
      if (k % i == 0) fact.push_back(i);
    }
    for (int j = 0; j < fact.size(); j++) {
      int len = fact[j];
      int no = v.front();
      for (no = v.front(); no <= v.back(); no++) {
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
          cnt += (v[i] / no);
        }
        if (cnt >= len) {
          ans = max(ans, no * len);
        }
      }
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
  return 0;
}
