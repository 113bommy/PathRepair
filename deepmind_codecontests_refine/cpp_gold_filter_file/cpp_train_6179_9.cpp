#include <bits/stdc++.h>
auto clk = clock();
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
const int dx8[] = {-1, -1, -1, 0, 1, 1, 1, 0},
          dy8[] = {-1, 0, 1, 1, 1, 0, -1, -1};
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long Gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return Gcd(b, a % b);
}
long long Max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long Min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
void printvector(std::vector<long long> v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << "" << endl;
}
void printarray(long long a[], long long n) {
  for (long long i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << "" << endl;
}
long long findlcm(vector<long long> arr, long long n) {
  long long ans = arr[0];
  for (int i = 1; i < n; i++) ans = (((arr[i] * ans)) / (Gcd(arr[i], ans)));
  return ans;
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return -1;
  else {
    long long res = (x % m + m) % m;
    return res;
  }
}
long long inverse(long long x, long long mod) { return power(x, mod - 2, mod); }
vector<long long> primeFactors(long long n) {
  vector<long long> v;
  while (n % 2 == 0) {
    v.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) v.push_back(n);
  return v;
}
long long lowerbound(long long k, vector<long long> v) {
  long long l = 0;
  long long size = v.size();
  long long r = size - 1;
  long long mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid] < k)
      l = mid + 1;
    else {
      r = mid - 1;
    }
  }
  return l;
}
long long upperbound(long long k, vector<long long> v) {
  long long l = 0;
  long long size = v.size();
  long long r = size - 1;
  long long mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid] > k)
      r = mid - 1;
    else {
      l = mid + 1;
    }
  }
  return l;
}
long long C[2001][2000];
void binomialCoeff(long long n, long long k) {
  long long i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= k; j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] % 1000000007 + C[i - 1][j] % 1000000007) %
                  1000000007;
    }
  }
}
string convertToNewString(const string &s) {
  string newString = "@";
  for (long long i = 0; i < s.size(); i++) {
    newString += "#" + s.substr(i, 1);
  }
  newString += "#$";
  return newString;
}
string longestPalindromeSubstring(const string &s) {
  string Q = convertToNewString(s);
  long long c = 0, r = 0;
  long long P[Q.size() + 4];
  memset(P, 0, sizeof(P));
  for (long long i = 1; i < Q.size() - 1; i++) {
    long long iMirror = c - (i - c);
    if (r > i) {
      P[i] = min(r - i, P[iMirror]);
    }
    while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]) {
      P[i]++;
    }
    if (i + P[i] > r) {
      c = i;
      r = i + P[i];
    }
  }
  int maxPalindrome = 0;
  int centerIndex = 0;
  for (int i = 1; i < Q.size() - 1; i++) {
    if (P[i] > maxPalindrome) {
      maxPalindrome = P[i];
      centerIndex = i;
    }
  }
  cout << maxPalindrome << "\n";
  return s.substr((centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}
long long spf[100010];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < 100010; i++) spf[i] = i;
  for (int i = 4; i < 100010; i += 2) spf[i] = 2;
  for (int i = 3; i * i < 100010; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < 100010; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
const long long N = 100000;
long long n, m;
long long tree[2 * N];
void build(long long arr[]) {
  for (long long i = 0; i < n; i++) {
    tree[n + i] = arr[i];
  }
  for (long long i = n - 1; i > 0; --i) {
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
  }
}
void updateTreeNode(long long p, long long value) {
  tree[p + n] = value;
  p = p + n;
  for (long long i = p; i > 1; i >>= 1) {
    tree[i >> 1] = tree[i] + tree[i ^ 1];
  }
}
long long query(long long l, long long r) {
  long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      res += tree[l++];
    }
    if (r & 1) {
      res += tree[--r];
    }
  }
  return res;
}
vector<long long> shortPath(vector<pair<long long, long long> > v[],
                            long long src, long long V = 0) {
  set<pair<long long, long long> > setds;
  long long sizee = V;
  long long IN = LLONG_MAX;
  vector<long long> dist(sizee, IN);
  vector<bool> vis(sizee, false);
  setds.insert(make_pair(0, src));
  dist[src] = 0;
  while (!setds.empty()) {
    pair<long long, long long> tmp = *(setds.begin());
    setds.erase(setds.begin());
    long long u = tmp.second;
    if (vis[u]) continue;
    vis[u] = true;
    vector<pair<long long, long long> >::iterator i;
    for (auto i = v[u].begin(); i != v[u].end(); ++i) {
      long long v = (*i).first;
      long long weight = (*i).second;
      if (dist[v] > dist[u] + weight) {
        if (dist[v] != LLONG_MAX)
          setds.erase(setds.find(make_pair(dist[v], v)));
        dist[v] = dist[u] + weight;
        setds.insert(make_pair(dist[v], v));
      }
    }
  }
  return dist;
}
long long root(long long a[], long long r) {
  if (a[r] == r) {
    return r;
  } else {
    long long x = root(a, a[r]);
    a[r] = x;
    return x;
  }
}
void unio(long long a[], long long size[], long long x, long long y) {
  x = root(a, x);
  y = root(a, y);
  if (x == y) {
    return;
  }
  if (size[x] >= size[y]) {
    a[y] = x;
    size[x] += size[y];
  } else {
    a[x] = y;
    size[y] += size[x];
  }
}
void dfs(std::vector<long long> v[], long long s, bool visited[]) {
  visited[s] = true;
  for (long long i = 0; i < v[s].size(); ++i) {
    if (!visited[v[s][i]]) {
      dfs(v, v[s][i], visited);
    }
  }
}
long long ver[1005][1005];
bool check(long long x, long long y) {
  if (x <= n && y <= n && x >= 1 && y > 0 && ver[x][y] == 1) {
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long txt = 1;
  while (txt--) {
    cin >> n;
    cin >> m;
    long long hor[n + 1][n + 1];
    long long mi = LLONG_MAX;
    for (int i = 0, _n = (m); i < _n; i++) {
      long long x, y;
      cin >> x >> y;
      ver[x][y] = 1;
      long long fl = 1;
      for (int k = (x), _b = (x + 2); k <= _b; k++) {
        for (int j = (y), _b = (y + 2); j <= _b; j++) {
          if (!check(k, j)) {
            fl = 0;
          }
        }
      }
      if (fl) mi = min(mi, (long long)i + 1);
      fl = 1;
      for (int k = (x), _b = (x + 2); k <= _b; k++) {
        for (int j = (y - 1), _b = (y + 1); j <= _b; j++) {
          if (!check(k, j)) {
            fl = 0;
          }
        }
      }
      if (fl) mi = min(mi, (long long)i + 1);
      fl = 1;
      for (int k = (x), _b = (x + 2); k <= _b; k++) {
        for (int j = (y - 2), _b = (y); j <= _b; j++) {
          if (!check(k, j)) {
            fl = 0;
          }
        }
      }
      if (fl) mi = min(mi, (long long)i + 1);
      fl = 1;
      x--;
      for (int k = (x), _b = (x + 2); k <= _b; k++) {
        for (int j = (y), _b = (y + 2); j <= _b; j++) {
          if (!check(k, j)) {
            fl = 0;
          }
        }
      }
      if (fl) mi = min(mi, (long long)i + 1);
      fl = 1;
      for (int k = (x), _b = (x + 2); k <= _b; k++) {
        for (int j = (y - 1), _b = (y + 1); j <= _b; j++) {
          if (!check(k, j)) {
            fl = 0;
          }
        }
      }
      if (fl) mi = min(mi, (long long)i + 1);
      fl = 1;
      for (int k = (x), _b = (x + 2); k <= _b; k++) {
        for (int j = (y - 2), _b = (y); j <= _b; j++) {
          if (!check(k, j)) {
            fl = 0;
          }
        }
      }
      if (fl) mi = min(mi, (long long)i + 1);
      fl = 1;
      x--;
      for (int k = (x), _b = (x + 2); k <= _b; k++) {
        for (int j = (y), _b = (y + 2); j <= _b; j++) {
          if (!check(k, j)) {
            fl = 0;
          }
        }
      }
      if (fl) mi = min(mi, (long long)i + 1);
      fl = 1;
      for (int k = (x), _b = (x + 2); k <= _b; k++) {
        for (int j = (y - 1), _b = (y + 1); j <= _b; j++) {
          if (!check(k, j)) {
            fl = 0;
          }
        }
      }
      if (fl) mi = min(mi, (long long)i + 1);
      fl = 1;
      for (int k = (x), _b = (x + 2); k <= _b; k++) {
        for (int j = (y - 2), _b = (y); j <= _b; j++) {
          if (!check(k, j)) {
            fl = 0;
          }
        }
      }
      if (fl) mi = min(mi, (long long)i + 1);
      fl = 1;
    }
    if (mi == LLONG_MAX) {
      cout << -1 << endl;
    } else {
      cout << mi << endl;
    }
  }
}
