#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 2000 + 10;
const int mod = 998244353;
int qpow(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) c = 1ll * c * a % mod;
  return c;
}
int n, m, deg[N], ans[N];
vector<int> E[N];
bitset<N> A[N];
void Gauss() {
  for (int i = 1; i <= n; ++i) {
    if (!A[i].test(i)) {
      for (int j = i + 1; j <= n; ++j)
        if (A[j].test(i)) {
          swap(A[i], A[j]);
          break;
        }
    }
    if (!A[i].test(i)) continue;
    for (int j = i + 1; j <= n; ++j)
      if (A[j].test(i)) A[j] ^= A[i];
  }
  for (int i = n; i; --i) {
    if (!A[i].test(i)) {
      ans[i] = 1;
      continue;
    }
    ans[i] = A[i].test(n + 1) + 1;
    for (int j = 1; j < i; ++j)
      if (A[j].test(i)) A[j] ^= A[i];
  }
}
int main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
      int u = read(), v = read();
      E[u].emplace_back(v), ++deg[v];
      E[v].emplace_back(u), ++deg[u];
    }
    int flag = 1;
    for (int i = 1; i <= n; ++i) flag &= !(deg[i] & 1);
    if (flag) {
      puts("1");
      for (int i = 1; i <= n; ++i) printf("1%c", " \n"[i == n]);
    } else {
      for (int i = 1; i <= n; ++i)
        for (int v : E[i]) A[i].flip(v), A[i].flip(i), A[i].flip(n + 1);
      Gauss();
      puts("2");
      for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    }
    for (int i = 1; i <= n; ++i) {
      E[i].clear(), deg[i] = 0;
      for (int j = 1; j <= n + 1; ++j) A[i].reset(j);
    }
  }
  return 0;
}
