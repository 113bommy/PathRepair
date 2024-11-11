#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7, p = 1e9 + 7;
int n, k, w[N], mu[N], ft[N];
vector<int> v[N], vt[N];
inline int pows(long long u, int v) {
  long long ans = 1;
  while (v > 0) {
    if (v & 1) ans = ans * u % p;
    u = u * u % p, v = v >> 1;
  }
  return ans;
}
inline int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  cin >> n >> k, mu[1] = 1;
  for (int i = 2; i <= n * 2; i++) {
    int c = i;
    mu[i] = 1;
    for (int x = 2; x * x <= i; x++) {
      if (c % x == 0) {
        mu[i] = -mu[i], c = c / x;
        while (c % x == 0) c /= x, mu[i] = 0;
      }
    }
    if (c > 1) mu[i] = -mu[i];
  }
  for (int i = 1; i <= 2 * n; i++)
    for (int x = i; x <= 2 * n; x += i) v[x].push_back(i);
  for (int i = 1; i < 2 * n - 1; i++) {
    int l = max(i - n, 0), r = min(i - 1, n - 1);
    vt[l].push_back(-i), vt[r].push_back(i);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x < v[i].size(); x++) ft[v[i][x]]++;
    for (int x = 0; x < vt[i].size(); x++) {
      int u = vt[i][x], fl = 0;
      if (u < 0) fl ^= 1, u = -u;
      if (fl)
        fl = -1;
      else
        fl = 1;
      for (int t = 0; t < v[u].size(); t++) {
        long long val = pows(k, max(u - n, v[u][t]));
        int z = u / v[u][t];
        for (int q = 0; q < v[z].size(); q++)
          ans = (ans + fl * mu[v[z][q]] * ft[v[z][q] * v[u][t]] * val) % p;
      }
    }
  }
  cout << (ans + p) * pows(pows(k, n), p - 2) % p << endl;
}
