#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
const int N = 100000 + 5;
const int mo = 1000000007;
int n, m, num;
int vis[N];
long long d[N];
long long pw[65], val[65];
long long c[65][2];
std::vector<int> v[N], id;
std::vector<long long> w[N];
void dfs(int x) {
  vis[x] = 1;
  id.push_back(x);
  for (int j = 0; j <= 63; j++) c[j][(d[x] >> j) & 1]++;
  for (int i = 0; i < v[x].size(); i++) {
    int y = v[x][i];
    if (vis[y]) continue;
    d[y] = d[x] ^ w[x][i];
    dfs(y);
  }
}
void add(long long x) {
  for (int i = 63; i; i--)
    if ((x >> i) & 1) {
      if (val[i])
        x ^= val[i];
      else {
        num++;
        val[i] = x;
        break;
      }
    }
}
int main() {
  read(n), read(m);
  for (int i = 1, x, y; i <= m; i++) {
    long long z;
    read(x), read(y), read(z);
    v[x].push_back(y), w[x].push_back(z);
    v[y].push_back(x), w[y].push_back(z);
  }
  pw[0] = 1;
  for (int i = 1; i <= 63; i++) pw[i] = pw[i - 1] * 2 % mo;
  long long ans = 0;
  for (int T = 1; T <= n; T++)
    if (!vis[T]) {
      for (int i = 0; i <= 63; i++) c[i][0] = c[i][1] = val[i] = 0;
      id.clear();
      dfs(T);
      num = 0;
      for (int i = 0; i < id.size(); i++) {
        int x = id[i];
        for (int j = 0; j < v[x].size(); j++) {
          int y = v[x][j];
          if (d[x] ^ d[y] ^ w[x][j]) {
            add(d[x] ^ d[y] ^ w[x][j]);
          }
        }
      }
      long long tmp = 0;
      for (int i = 1; i <= 63; i++) tmp |= val[i];
      for (int i = 0; i < id.size(); i++) {
        int x = id[i];
        for (int j = 0; j <= 63; j++) {
          if (tmp & (1LL << j)) {
            (ans += pw[j] * c[j][0] % mo * pw[num - 1] % mo) %= mo;
            (ans += pw[j] * c[j][1] % mo * pw[num - 1] % mo) %= mo;
            (ans -= pw[j] * pw[num - 1] % mo) %= mo;
          } else {
            (ans += pw[j] * c[j][!((d[x] >> j) & 1)] % mo * pw[num] % mo) %= mo;
          }
        }
      }
    }
  ans = ans * ((mo + 1) / 2) % mo;
  printf("%lld\n", (ans + mo) % mo);
  return 0;
}
