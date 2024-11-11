#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, mod = 998244353, proot = 3,
          fft_maxn = (1 << 18) | 10;
vector<int> g[maxn];
int n, k, ans, f[maxn], fac[maxn], ifac[maxn], siz[maxn];
inline int pow_mod(int x, int n) {
  int y = 1;
  while (n) {
    if (n & 1) {
      y = (long long)y * x % mod;
    }
    x = (long long)x * x % mod;
    n >>= 1;
  }
  return y;
}
inline void dft(int n, int *a, bool rev) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i < j) {
      swap(a[i], a[j]);
    }
    for (int k = n >> 1; (j ^= k) < k; k >>= 1)
      ;
  }
  for (int hl = 1, l = 2; l <= n; hl = l, l <<= 1) {
    int wn = pow_mod(proot, (mod - 1) / l);
    if (rev) {
      wn = pow_mod(wn, mod - 2);
    }
    for (int i = 0; i < n; i += l) {
      int *x = a + i, *y = x + hl, w = 1;
      for (int j = 0; j < hl; ++j, ++x, ++y, w = (long long)w * wn % mod) {
        int t = (long long)w * *y % mod;
        *y = (*x - t) % mod;
        *x = (*x + t) % mod;
      }
    }
  }
  if (rev) {
    int inv = pow_mod(n, mod - 2);
    for (int i = 0; i < n; ++i) {
      a[i] = (long long)a[i] * inv % mod;
    }
  }
  return;
}
inline void mul(vector<int> &a, vector<int> &b, vector<int> &c) {
  static int A[fft_maxn], B[fft_maxn];
  int sa = a.size(), sb = b.size(), sc = sa + sb - 1, N = 1;
  if (sa <= 20 && sb <= 20 || sa <= 5 || sb <= 5) {
    static long long C[fft_maxn];
    memset(C, 0, sizeof(C[0]) * sc);
    for (int i = 0; i < sa; ++i) {
      int &x = a[i];
      long long *c = C + i;
      for (int j = 0; j < sb; ++j) {
        c[j] += (long long)x * b[j];
        if ((j & 7) == 7) {
          c[j] %= mod;
        }
      }
    }
    c.resize(sc);
    for (int i = 0; i < sc; ++i) {
      c[i] = C[i] % mod;
    }
    return;
  }
  while (N <= sc - 1) {
    N <<= 1;
  }
  for (int i = 0; i < N; ++i) {
    A[i] = (i < sa ? a[i] : 0);
    B[i] = (i < sb ? b[i] : 0);
  }
  dft(N, A, 0);
  dft(N, B, 0);
  for (int i = 0; i < N; ++i) {
    A[i] = (long long)A[i] * B[i] % mod;
  }
  dft(N, A, 1);
  c.resize(sc);
  for (int i = 0; i < sc; ++i) {
    c[i] = A[i];
  }
  return;
}
inline void dfs(int u, int par) {
  vector<vector<int> > p;
  int sum = 0;
  siz[u] = 1;
  p.push_back(vector<int>{1});
  for (int &v : g[u]) {
    if (v != par) {
      dfs(v, u);
      ans = ((long long)sum * f[v] + ans) % mod;
      sum = (sum + f[v]) % mod;
      p.push_back(vector<int>{1, siz[v]});
      siz[u] += siz[v];
      while (p.size() > 1 && p.back().size() >= p[p.size() - 2].size()) {
        mul(p.back(), p[p.size() - 2], p[p.size() - 2]);
        p.pop_back();
      }
    }
  }
  while (p.size() > 1) {
    mul(p.back(), p[p.size() - 2], p[p.size() - 2]);
    p.pop_back();
  }
  auto &P = p[0];
  for (int i = 0, i_end = min(k, (int)P.size() - 1); i <= i_end; ++i) {
    f[u] = ((long long)P[i] * ifac[k - i] + f[u]) % mod;
  }
  f[u] = ((long long)f[u] * fac[k] + sum) % mod;
  if (siz[u] < n) {
    vector<int> foo = vector<int>{1, n - siz[u]};
    mul(P, foo, P);
  }
  sort(g[u].begin(), g[u].end(), [&](int u, int v) {
    if (u == par) {
      return true;
    }
    if (v == par) {
      return false;
    }
    return siz[u] < siz[v];
  });
  int SZ = P.size();
  vector<int> nP(SZ - 1);
  for (int i = 0; i < g[u].size(); ++i) {
    if (g[u][i] != par) {
      int &sz = siz[g[u][i]], val = 0;
      nP[0] = P[0];
      for (int j = 1; j < SZ - 1; ++j) {
        nP[j] = ((long long)P[j] - (long long)nP[j - 1] * sz) % mod;
      }
      for (int j = 0, j_end = min(k, (int)nP.size() - 1); j <= j_end; ++j) {
        val = ((long long)nP[j] * ifac[k - j] + val) % mod;
      }
      val = (long long)val * fac[k] % mod;
      --i;
      while (i + 1 < g[u].size() && siz[g[u][i + 1]] == sz) {
        ++i;
        ans = ((long long)val * f[g[u][i]] + ans) % mod;
      }
    }
  }
  return;
}
int main() {
  scanf("%d%d", &n, &k);
  if (k == 1) {
    printf("%d\n", ((long long)n * (n - 1) >> 1) % mod);
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int N = max(n, k);
  fac[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fac[i] = (long long)fac[i - 1] * i % mod;
  }
  ifac[N] = pow_mod(fac[N], mod - 2);
  for (int i = N; i; --i) {
    ifac[i - 1] = (long long)ifac[i] * i % mod;
  }
  dfs(1, 0);
  printf("%d\n", (ans + mod) % mod);
  return 0;
}
