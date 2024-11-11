#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 2e7 + 7;
bool fl[M];
long long g, n, m, p, q, w, st[N], f[6] = {2, 3, 5, 7, 11, 13};
inline long long mul(long long a, long long b, long long p) {
  long long ans = 0;
  while (b > 0) {
    if (b & 1) {
      ans += a;
      if (ans >= p) ans -= p;
    }
    a += a;
    if (a >= p) a -= p;
    b = b >> 1;
  }
  return ans;
}
inline long long pows(long long a, long long b, long long p) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = mul(ans, a, p);
    a = mul(a, a, p), b = b >> 1;
  }
  return ans;
}
inline bool miller_rabin(long long d) {
  if (d == 2 || d == 3 || d == 5 || d == 7 || d == 11 || d == 13) return 1;
  if (d % 2 == 0) return 0;
  int k = 0;
  long long z = d - 1;
  while (z % 2 == 0) k++, z /= 2;
  for (int i = 0; i <= 5; i++) {
    long long v = pows(f[i], z, d), w = v;
    for (int c = 1; c <= k; c++) {
      v = mul(v, v, d);
      if (v == 1 && w != 1 && w != d - 1) return 0;
      w = v;
    }
    if (w != 1 && w != d - 1) return 0;
    if (v != 1) return 0;
  }
  return 1;
}
inline long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
inline void pollard_rho(long long d) {
  if (d == 1) return;
  if (d % 2 == 0) {
    st[++st[0]] = 2, pollard_rho(d / 2);
    return;
  }
  if (d % 3 == 0) {
    st[++st[0]] = 3, pollard_rho(d / 3);
    return;
  }
  if (d % 5 == 0) {
    st[++st[0]] = 5, pollard_rho(d / 5);
    return;
  }
  if (miller_rabin(d)) {
    st[++st[0]] = d;
    return;
  }
  long long c = rand() % 1000 + 1, x = 1ll * rand() * rand() * rand() % d,
            y = x;
  while (1) {
    x = mul(x, x, d) + c;
    if (x >= d) x -= d;
    y = mul(y, y, d) + c;
    if (y >= d) y -= d;
    y = mul(y, y, d) + c;
    if (y >= d) y -= d;
    long long t = gcd(x - y, d);
    if (1 < t && t < d) {
      pollard_rho(t), pollard_rho(d / t);
      return;
    }
    if (t == d) {
      pollard_rho(d);
      return;
    }
  }
}
inline void dfs(int u, long long k) {
  if (u == st[0] + 1) {
    if (pows(m, q / k, p) == 1) w = max(w, k);
    return;
  }
  dfs(u + 1, k * st[u]);
  for (int i = u + 1; u <= st[0]; i++) {
    if (st[i] != st[u]) {
      dfs(i, k);
      break;
    }
  }
}
int main() {
  cin >> n >> p >> m;
  m %= p;
  pollard_rho(p);
  if (p <= 2e7) {
    long long v = m;
    while (!fl[v]) fl[v] = 1, v = mul(v, m, p);
    int cnt = 0;
    for (int i = 0; i < p; i += st[1]) fl[i] = 1;
    fl[1] = 1;
    for (int i = 0; i < p; i++)
      if (!fl[i]) cnt++;
    if (cnt < n) {
      cout << -1 << endl;
      return 0;
    }
    for (int i = 0; i < p; i++)
      if (!fl[i] && n > 0) n--, printf("%d ", i);
    cout << endl;
    return 0;
  }
  if (m % st[1] == 0) {
    for (int i = 0; i < p; i++) {
      if (i % st[1]) printf("%d ", i), n--;
      if (n == 0) break;
    }
    return 0;
  }
  if (st[1] != 2) {
    q = st[1] - 1;
    for (int i = 2; i <= st[0]; i++) q = q * st[i];
    st[0]--;
    long long x = st[1];
    pollard_rho(st[1] - 1);
    sort(st + 1, st + st[0] + 1), dfs(1, 1);
    if (w == 1) {
      cout << -1 << endl;
      return 0;
    }
    for (int i = 2; i <= p; i++) {
      bool z = 0;
      for (int j = 1; j <= st[0]; j++) {
        if (pows(i, q / st[j], p) == 1) z = 1;
      }
      if (z) continue;
      g = i;
      break;
    }
    long long s = pows(g, q / w, p), c = g;
    for (int i = 2; i <= p; i++) {
      c = mul(c, g, p);
      if (i % w) printf("%lld ", c), n--;
      if (n == 0) break;
    }
    return 0;
  }
  if (m % 4 == 1) {
    for (int i = 2; i < p; i++) {
      if (i % 4 == 3) {
        printf("%d ", i), n--;
      }
      if (n == 0) break;
    }
    return 0;
  }
  long long c = mul(m, m, p);
  if (pows(c, p / 8, p) > 1) {
    cout << -1 << endl;
    return 0;
  }
  c = 5;
  g = 5;
  for (int i = 1; i <= p; i++) {
    if (i % (p / 8)) {
      if (n >= 2)
        printf("%lld %lld ", c, mul(c, m, p)), n -= 2;
      else
        printf("%lld ", c), n--;
    }
    if (n == 0) break;
    c = mul(c, g, p);
  }
}
