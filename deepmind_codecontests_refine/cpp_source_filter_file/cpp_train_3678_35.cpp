#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111111;
vector<int> g[MAXN];
int a[MAXN];
int len, cnt, n, m, x, y, i, j;
long long MODUL;
bool used[MAXN];
void dfs(int v) {
  cnt++;
  used[v] = true;
  for (size_t i = 0; i < g[v].size(); i++) {
    if (!used[g[v][i]]) dfs(g[v][i]);
  }
}
template <class T>
T sqr(T a) {
  return a * a;
}
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1) return (binpow(a, n - 1) * a) % MODUL;
  return sqr(binpow(a, n / 2)) % MODUL;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> MODUL;
  while (m--) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i = 1; i <= n; i++) {
    if (!used[i]) {
      cnt = 0;
      dfs(i);
      a[len++] = cnt;
    }
  }
  long long ans;
  if (len == 1) {
    ans = 1;
  } else {
    ans = 1;
    ans = binpow(n, len - 2);
    for (i = 0; i < len; i++) ans = (ans * (long long)a[i]) % MODUL;
  }
  cout << ans;
  return 0;
}
