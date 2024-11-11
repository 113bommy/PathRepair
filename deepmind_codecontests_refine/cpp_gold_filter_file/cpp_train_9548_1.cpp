#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, MOD = 520717;
template <typename T>
void read(T &x) {
  bool neg = false;
  unsigned char c = getchar();
  for (; (c ^ 48) > 9; c = getchar())
    if (c == '-') neg = true;
  for (x = 0; (c ^ 48) < 10; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  if (neg) x = -x;
}
namespace hash1 {
int hd[MOD], next1[N], cnt;
unsigned long long val[N];
}  // namespace hash1
namespace g {
struct line {
  int next1, to;
} e[2 * N];
int cnt;
}  // namespace g
namespace g1 {
using g::cnt;
using g::e;
int hd[N];
void adline(int u, int v) {
  e[cnt].to = v;
  e[cnt].next1 = hd[u];
  hd[u] = cnt++;
}
}  // namespace g1
namespace g2 {
using g::cnt;
using g::e;
int hd[N];
void adline(int u, int v) {
  e[cnt].to = v;
  e[cnt].next1 = hd[u];
  hd[u] = cnt++;
}
}  // namespace g2
using g::e;
int n, m, u[N], v[N], in[N], out[N], deg[N], tot;
unsigned long long A, B, C, ans;
bool is(int u, int v) {
  using namespace hash1;
  if (u > v) u ^= v ^= u ^= v;
  unsigned long long h = (unsigned long long)u * n + v;
  for (int i = hd[h % MOD]; ~i; i = next1[i])
    if (val[i] == h) return true;
  return false;
}
int main() {
  for (int i = 0, i_end = MOD; i < i_end; ++i) hash1::hd[i] = -1;
  read(n);
  read(m);
  read(A);
  read(B);
  read(C);
  for (int i = 0, i_end = m; i < i_end; ++i) {
    read(u[i]);
    read(v[i]);
    if (u[i] > v[i]) u[i] ^= v[i] ^= u[i] ^= v[i];
    ++out[u[i]];
    ++in[v[i]];
    using namespace hash1;
    unsigned long long h = (unsigned long long)u[i] * n + v[i];
    val[cnt] = h;
    next1[cnt] = hd[h % MOD];
    hd[h % MOD] = cnt++;
  }
  for (int i = 0, i_end = n; i < i_end; ++i) g1::hd[i] = g2::hd[i] = -1;
  for (int i = 0, i_end = m; i < i_end; ++i) {
    g1::adline(u[i], v[i]);
    g2::adline(v[i], u[i]);
  }
  for (int i = 0, i_end = m; i < i_end; ++i) ++deg[u[i]], ++deg[v[i]];
  tot = m;
  for (int i = 0, i_end = n; i < i_end; ++i) {
    {
      using namespace g1;
      deg[i] = 0;
      for (int j = hd[i]; ~j; j = e[j].next1) --deg[e[j].to];
      tot -= out[i];
    }
    if ((long long)out[i] * out[i] > n) {
      ans += A * (n - 1 - i - out[i]) * (n - 2 - i - out[i]) / 2 * i;
      for (int j = 0, j_end = m; j < j_end; ++j)
        if (u[j] > i && !is(i, u[j]) && !is(i, v[j])) ans -= A * i;
    } else {
      using namespace g1;
      ans += A * (n - 1 - i - out[i]) * (n - 2 - i - out[i]) / 2 * i;
      ans -= A * tot * i;
      for (int j = hd[i]; ~j; j = e[j].next1) {
        int u = e[j].to;
        ans += A * deg[u] * i;
      }
      for (int j = hd[i]; ~j; j = e[j].next1) {
        int u = e[j].to;
        for (int k = e[j].next1; ~k; k = e[k].next1) {
          int v = e[k].to;
          if (is(u, v)) ans -= A * i;
        }
      }
    }
  }
  tot = 0;
  for (int i = 0, i_end = n; i < i_end; ++i) deg[i] = 0;
  for (int i = 0, i_end = n; i < i_end; ++i) {
    if ((long long)in[i] * out[i] > n) {
      ans += B * (i - in[i]) * (n - 1 - i - out[i]) * i;
      for (int j = 0, j_end = m; j < j_end; ++j)
        if (u[j] < i && v[j] > i && !is(i, u[j]) && !is(i, v[j])) ans -= B * i;
    } else {
      ans += B * (i - in[i]) * (n - 1 - i - out[i]) * i;
      ans -= B * tot * i;
      for (int j = g1::hd[i]; ~j; j = e[j].next1) {
        int u = e[j].to;
        ans += B * deg[u] * i;
      }
      for (int j = g2::hd[i]; ~j; j = e[j].next1) {
        int u = e[j].to;
        ans += B * deg[u] * i;
      }
      for (int j = g1::hd[i]; ~j; j = e[j].next1) {
        int u = e[j].to;
        for (int k = g2::hd[i]; ~k; k = e[k].next1) {
          int v = e[k].to;
          if (is(u, v)) ans -= B * i;
        }
      }
    }
    {
      using namespace g1;
      for (int j = hd[i]; ~j; j = e[j].next1) {
        int u = e[j].to;
        if (u > i + 1) {
          ++deg[i];
          ++deg[u];
          ++tot;
        }
      }
    }
    if (i != n - 1) {
      using namespace g2;
      for (int j = hd[i + 1]; ~j; j = e[j].next1) {
        int u = e[j].to;
        if (u < i) {
          --deg[i + 1];
          --deg[u];
          --tot;
        }
      }
    }
  }
  for (int i = 0, i_end = m; i < i_end; ++i) deg[i] = 0;
  for (int i = 0, i_end = m; i < i_end; ++i) ++deg[u[i]], ++deg[v[i]];
  tot = m;
  for (int i = n - 1; ~i; --i) {
    {
      using namespace g2;
      deg[i] = 0;
      for (int j = hd[i]; ~j; j = e[j].next1) --deg[e[j].to];
      tot -= in[i];
    }
    if ((long long)in[i] * in[i] > n) {
      ans += C * (i - in[i]) * (i - in[i] - 1) / 2 * i;
      for (int j = 0, j_end = m; j < j_end; ++j)
        if (v[j] < i && !is(i, u[j]) && !is(i, v[j])) ans -= C * i;
    } else {
      using namespace g2;
      ans += C * (i - in[i]) * (i - in[i] - 1) / 2 * i;
      ans -= C * tot * i;
      for (int j = hd[i]; ~j; j = e[j].next1) {
        int u = e[j].to;
        ans += C * deg[u] * i;
      }
      for (int j = hd[i]; ~j; j = e[j].next1) {
        int u = e[j].to;
        for (int k = e[j].next1; ~k; k = e[k].next1) {
          int v = e[k].to;
          if (is(u, v)) ans -= C * i;
        }
      }
    }
  }
  printf("%llu\n", ans);
  return 0;
}
