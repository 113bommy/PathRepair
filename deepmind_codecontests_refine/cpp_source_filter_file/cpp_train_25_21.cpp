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
  char c[n][n];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) cin >> c[i][j];
  if (c[0][2] == c[1][1] && c[0][2] == c[2][0]) {
    if (c[0][2] == '0') {
      if (c[0][1] == c[1][0]) {
        if (c[0][1] == '1')
          cout << 0 << endl;
        else {
          cout << 2 << endl;
          cout << "1 2" << endl;
          cout << "2 1" << endl;
        }
      } else {
        cout << 1 << endl;
        if (c[0][1] == '0') {
          cout << "1 2" << endl;
        } else
          cout << "2 1" << endl;
      }
    } else {
      if (c[0][1] == c[1][0]) {
        if (c[0][1] == '0')
          cout << 0 << endl;
        else {
          cout << 2 << endl;
          cout << "1 2" << endl;
          cout << "2 1" << endl;
        }
      } else {
        cout << 1 << endl;
        if (c[0][1] == '1') {
          cout << "1 2" << endl;
        } else
          cout << "2 1" << endl;
      }
    }
  } else {
    vector<pair<long long, long long> > v;
    if (c[0][1] == c[1][0]) {
      if (c[0][1] == '0') {
        long long i = 0, j = 2;
        long long cnt = 0;
        while (i < 3) {
          if (c[i][j] == '0') {
            v.push_back({i, j});
          }
          i++;
          j--;
        }
        cout << v.size() << endl;
        for (auto x : v) cout << x.first + 1 << " " << x.second + 1 << endl;
      } else {
        long long i = 0, j = 2;
        while (i < 3) {
          if (c[i][j] == '1') {
            v.push_back({i, j});
          }
          i++;
          j--;
        }
        cout << v.size() << endl;
        for (auto x : v) cout << x.first + 1 << " " << x.second + 1 << endl;
      }
    } else {
      long long i = 0, j = 2;
      while (i < 3) {
        if (c[i][j] == '0') {
          v.push_back({i, j});
        }
        i++;
        j--;
      }
      cout << 2 << endl;
      if (v.size() == 1) {
        cout << v[0].first + 1 << " " << v[1].second + 1 << endl;
        if (c[0][1] == '1') {
          cout << "1 2" << endl;
        } else
          cout << "2 1" << endl;
      } else {
        map<pair<long long, long long>, long long> mp;
        for (auto x : v) mp[{x.first, x.second}] = 1;
        i = 0, j = 2;
        while (i < 3) {
          if (mp[{i, j}] == 0) {
            cout << i + 1 << " " << j + 1 << endl;
            break;
          }
          i++;
          j--;
        }
        if (c[0][1] == '0') {
          cout << "1 2" << endl;
        } else
          cout << "2 1" << endl;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
