#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long linf = 1ll << 60;
const double dinf = 1e60;
template <typename T>
inline void scf(T &x) {
  bool f = 0;
  x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) {
  scf(x);
  return scf(y);
}
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) {
  scf(x);
  scf(y);
  return scf(z);
}
template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) {
  scf(x);
  scf(y);
  scf(z);
  return scf(w);
}
inline char mygetchar() {
  char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
template <typename T>
void chkmax(T &x, const T &y) {
  if (y > x) x = y;
  return;
}
template <typename T>
void chkmin(T &x, const T &y) {
  if (y < x) x = y;
  return;
}
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
int n;
bool is_prime[N];
int match_prime[N];
int appearance[N];
vector<int> prime_factor[N];
bool vis[N];
int same_type[N];
bool special_case[N];
int factorial[N];
int ancestor[N];
vector<int> has[N];
void dfs(int u, int root) {
  if (vis[u]) return;
  vis[u] = 1;
  same_type[root]++;
  ancestor[u] = root;
  for (int x : prime_factor[root])
    if (1ll * u * x <= 1ll * n) dfs(u * x, root);
  return;
}
void MEI() {
  scf(n);
  for (int i = (2); i <= (n); ++i) is_prime[i] = 1;
  for (int i = (2); i <= (n); ++i)
    if (is_prime[i]) {
      prime_factor[i].push_back(i);
      for (int j = i + i; j <= n; j += i) {
        prime_factor[j].push_back(i);
        is_prime[j] = 0;
      }
    }
  factorial[0] = 1;
  for (int i = (1); i <= (n); ++i)
    factorial[i] = 1ll * factorial[i - 1] * i % mod;
  special_case[1] = 1;
  for (int i = (n / 2 + 1); i <= (n); ++i)
    if (is_prime[i]) special_case[i] = 1;
  for (int i = (1); i <= (n); ++i)
    if (!special_case[i] && !vis[i]) dfs(i, i);
  for (int i = (1); i <= (n); ++i)
    if (!special_case[i] && is_prime[i])
      appearance[i] = n / i, has[appearance[i]].push_back(i);
  return;
}
void ZI() {
  for (int i = (1); i <= (n); ++i) {
    int j;
    scf(j);
    if (!j) continue;
    bool fi = (i == 1 || i > n / 2 && is_prime[i]);
    bool fj = (j == 1 || j > n / 2 && is_prime[j]);
    if (fi != fj) {
      puts("0");
      return;
    }
    if (fi && fj) {
      special_case[i] = 0;
      continue;
    }
    if ((int)prime_factor[j].size() != (int)prime_factor[i].size()) {
      puts("0");
      return;
    }
    for (int k = 0; k < ((int)prime_factor[j].size()); ++k) {
      int x = prime_factor[i][k], y = prime_factor[j][k];
      if (appearance[x] != appearance[y]) {
        puts("0");
        return;
      }
      if (match_prime[x] && match_prime[x] != y) {
        puts("0");
        return;
      }
      match_prime[x] = y;
    }
    same_type[ancestor[i]]--;
  }
  int ans = 0;
  for (int i = (1); i <= (n); ++i)
    if (special_case[i]) ++ans;
  ans = factorial[ans];
  ;
  for (int i = (2); i <= (n); ++i)
    if (ancestor[i] == i) ans = 1ll * ans * factorial[same_type[i]] % mod;
  ;
  for (int i = (1); i <= (n); ++i)
    if ((int)has[i].size()) {
      int foo = 0;
      for (int x : has[i])
        if (!match_prime[x]) ++foo;
      ans = 1ll * ans * factorial[foo] % mod;
    }
  printf("%d\n", ans);
  return;
}
int main() {
  MEI();
  ZI();
  return 0;
}
