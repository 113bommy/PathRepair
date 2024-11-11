#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y);
long long int mpower(long long int x, long long int y, long long int p);
long long int modInv(long long int a, long long int m);
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y);
bool isPrime(long long int n);
long long int lvl[1000][1000];
bool A[1000][1000];
long long int modInv(long long int a, long long int m) {
  long long int x, y;
  long long int g = gcdExtended(a, m, &x, &y);
  long long int res = (x % m + m) % m;
  return res;
}
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long int gcd(long long int x, long long int y) {
  return (x == 0) ? y : gcd(y % x, x);
}
long long int mpower(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
void addEdge(vector<long long int> adj[], long long int u, long long int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long int p = sqrt(n);
  for (int i = 5; i <= p; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int pow(long long int base, long long int expo, long long int m) {
  if (m == 1) return 0;
  long long int ans = 1, y = base % m;
  while (expo > 0) {
    if (expo & 1) ans = ((ans)*y) % m;
    y = (y * y) % m;
    if (y < 0) y += m;
    expo = expo >> 1;
  }
  if (ans < 0) {
    ans = (m - abs(ans) % m);
    return ans;
  }
  return ans % m;
}
vector<long long int> Divisors(long long int n) {
  vector<long long int> vec;
  vec.clear();
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        vec.push_back(i);
      } else {
        vec.push_back(i);
        vec.push_back(n / i);
      }
    }
  }
  return vec;
}
void DFSE(vector<long long int> adj[], vector<bool> &visited, long long int u) {
  long long int i;
  visited[u] = true;
  cout << u << " ";
  for (long long int i = 0; i < adj[u].size(); i++) {
    if (visited[adj[u][i]] == false) {
      DFSE(adj, visited, adj[u][i]);
    }
  }
}
void DFS(vector<long long int> adj[], long long int u, long long int v) {
  long long int i;
  vector<bool> visited(v, false);
  for (long long int i = 0; i < v; i++) {
    if (visited[i] == false) {
      DFSE(adj, visited, i);
    }
  }
}
void slv() {
  long long int t, n, m, q, d, z, c, h, e, u, i, j, o, f, r, l, x, y, a, k, b,
      p, v;
  string s, s1, s2;
  cin >> d >> n;
  long long int ar[n];
  for (long long int i = 0; i < n; i++) cin >> ar[i];
  i = 0;
  k = 0;
  while (ar[i] == d && i < n) i++;
  j = i;
  for (; j + 1 < n; j++) {
    k += (d - ar[j]);
  }
  cout << k << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    slv();
  }
  return 0;
}
