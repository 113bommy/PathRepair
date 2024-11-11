#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = 6105;
const int mod = 1e9 + 7;
inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline int mul(int x, int y) { return (x * 1ll * y) % mod; }
inline int powr(int a, long long b) {
  int x = 1 % mod;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a) { return powr(a, mod - 2); }
int first[3005][N], G[3005][N];
vector<int> con[N];
long long lagrange(vector<long long>& v, int k, long long x, int mod) {
  if (x <= k) return v[x];
  long long inn = 1;
  long long den = 1;
  for (int i = 1; i <= k; i++) {
    inn = (inn * (x - i)) % mod;
    den = (den * (mod - i)) % mod;
  }
  inn = (inn * inv(den % mod)) % mod;
  long long ret = 0;
  for (int i = 0; i <= k; i++) {
    ret = (ret + v[i] * inn) % mod;
    long long md1 = mod - ((x - i) * (k - i)) % mod;
    long long md2 = ((i + 1) * (x - i - 1)) % mod;
    if (i != k) inn = (((inn * md1) % mod) * inv(md2 % mod)) % mod;
  }
  return ret;
}
void dfs(int s = 1, int p = 0) {
  int bigc = 0;
  for (int i = 1; i < N; i++) first[s][i] = 1;
  for (int v : con[s]) {
    if (v != p) {
      dfs(v, s);
      for (int i = 1; i < N; i++) {
        first[s][i] = mul(first[s][i], G[v][i]);
      }
    }
  }
  for (int j = 1; j < N; j++) G[s][j] = add(first[s][j], G[s][j - 1]);
}
vector<long long> v;
int main() {
  int n, D;
  scanf("%d", &(n));
  scanf("%d", &(D));
  for (int i = 1; i < n; i++) {
    int j;
    scanf("%d", &(j));
    int u = i + 1, v = j;
    con[u].push_back(v);
    con[v].push_back(u);
  }
  dfs();
  for (int i = 0; i < N; i++) {
    v.push_back(G[1][i]);
  }
  printf("%lld\n", lagrange(v, N - 1, D, mod));
}
