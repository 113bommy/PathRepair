#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
const double esp = 1e-12;
const unsigned long long base = 1331;
int phi[N], p[N], tot;
bool st[N];
void init() {
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!st[i]) phi[i] = i - 1, p[tot++] = i;
    for (int j = 0; j < tot && 1ll * i * p[j] < N; j++) {
      st[i * p[j]] = 1;
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i * p[j]] = phi[i] * (p[j] - 1);
    }
  }
}
long long qpow(long long x, long long y, long long p) {
  long long ans = 1;
  while (y) {
    if (y & 1) {
      ans = ans * x;
      if (ans >= p) ans = ans % p + p;
    }
    x = x * x;
    if (x >= mod) x = x % p + p;
    y >>= 1;
  }
  return ans;
}
vector<int> v;
long long s[N];
int Phi(int x) {
  int ans = x;
  for (int i = 0; i < tot && p[i] * p[i] <= x; i++) {
    if (x % p[i] == 0) {
      ans = ans / p[i] * (p[i] - 1);
      while (x % p[i] == 0) x /= p[i];
    }
  }
  if (x > 1) ans = ans / x * (x - 1);
  return ans;
}
void Init(int p) {
  while (p > 1) {
    v.push_back(p);
    if (p >= N)
      p = Phi(p);
    else
      p = phi[p];
  }
}
int main() {
  init();
  int n, m;
  cin >> n >> m;
  Init(m);
  v.push_back(1);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    long long ans = 1;
    int k = min((int)v.size(), r - l + 1);
    while (k) {
      int id = l + k - 1;
      ans = qpow(s[id], ans, v[k - 1]);
      k--;
    }
    cout << ans % m << endl;
  }
}
