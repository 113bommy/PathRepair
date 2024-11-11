#include <bits/stdc++.h>
using namespace std;
const long long N = 1000001, INF = 2000000000000000000;
const long double EPS = 0.000000000001;
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
vector<int> prime;
bool isprime[N];
void pre() {
  for (int i = 2; i < N; i++) {
    if (isprime[i]) {
      for (int j = i * i; j < N; j += i) isprime[j] = false;
      prime.push_back(i);
    }
  }
  return;
}
double fn_ternary(double b, double c, double x) {
  double ans = (x * x + b * x + c) / (sin(x));
  return ans;
}
double ternary_search(double l, double r, double b, double c) {
  double eps = 1e-10;
  while (r - l > eps) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = fn_ternary(b, c, m1);
    double f2 = fn_ternary(b, c, m2);
    if (f1 < f2) {
      r = m2;
    } else {
      l = m1;
    }
  }
  return fn_ternary(b, c, l);
}
long long binary_search(long long a[], int n, long long k) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (a[m] == k) {
      return m;
    } else if (a[m] >= k) {
      r = m - 1;
    } else if (a[m] < k) {
      l = m + 1;
    }
  }
  return -1;
}
long long modinverse(long long n, long long p) { return power(n, p - 2, p); }
long long nCr(long long n, long long r, long long p) {
  long long f[n + 1];
  f[0] = 1;
  for (long long i = 1; i <= n; i++) {
    f[i] = f[i - 1] * i % p;
  }
  return (f[n] % p * modinverse(f[r], p) % p * modinverse(f[n - r], p) % p) % p;
}
int vis[10];
vector<int> adj[10];
void edge(int a, int b) {
  adj[a].push_back(b);
  adj[b].push_back(a);
}
void bfs(int u, int n) {
  vis[u] = true;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    q.pop();
    for (int x : adj[u]) {
      if (!vis[x]) {
        q.push(x);
        vis[x] = true;
      }
    }
  }
}
void dfs(int u, int n) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (vis[v]) {
      continue;
    } else {
      dfs(v, n);
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    return 0;
  }
  cout << 1 << " " << n << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << -a[i] * n << " ";
  }
  cout << 0 << endl;
  cout << 1 << " " << n - 1 << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << (n - 1) * a[i] << " ";
  }
  cout << endl;
  cout << n << " " << n << endl;
  cout << -a[n - 1] << endl;
  return 0;
}
