#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 10;
int h[N], r[N], c[N][N], a[30], n, s, tmp, p[10], cnt, num;
bool use[30], ok;
unordered_map<int, int> M[5];
void dfs(int x, int y) {
  if (y > n) {
    x++;
    y = 1;
  }
  if (x == n) {
    for (int j = (1); j < (n + 1); j++) {
      ok = 0;
      for (int i = (0); i < (n * n); i++)
        if (!use[i] && a[i] + h[j] == s) {
          use[i] = 1;
          c[n][j] = a[i];
          p[j] = i;
          ok = 1;
          break;
        }
      if (!ok) {
        for (int i = (1); i < (j); i++) use[p[i]] = 0;
        return;
      }
    }
    tmp = 0;
    for (int i = (1); i < (n + 1); i++) tmp += c[i][i];
    if (tmp != s) {
      for (int i = (1); i < (n + 1); i++) use[p[i]] = 0;
      return;
    }
    tmp = 0;
    for (int i = (1); i < (n + 1); i++) tmp += c[i][n - i + 1];
    if (tmp != s) {
      for (int i = (1); i < (n + 1); i++) use[p[i]] = 0;
      return;
    }
    cout << s << "\n";
    for (int i = (1); i < (n + 1); i++) {
      for (int j = (1); j < (n + 1); j++) cout << c[i][j] << " ";
      cout << "\n";
    }
    exit(0);
  }
  set<int> S;
  int cnt = 0;
  for (int i = (0); i < (n * n); i++)
    if (!use[i]) {
      if (y == n && a[i] + r[x] != s) continue;
      if (x == n && a[i] + h[y] != s) continue;
      if (S.count(a[i]) || !M[n - y].count(s - a[i] - r[x]) ||
          !M[n - x].count(s - a[i] - h[y]))
        continue;
      use[i] = 1;
      S.insert(a[i]);
      r[x] += a[i];
      h[y] += a[i];
      c[x][y] = a[i];
      dfs(x, y + 1);
      r[x] -= a[i];
      h[y] -= a[i];
      use[i] = 0;
      cnt++;
      if (cnt > 8) break;
      if (y == n) break;
      if (x == n) break;
    }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n;
  for (int i = (0); i < (n * n); i++) cin >> a[i], s += a[i];
  sort(a + 1, a + n + 1);
  for (int i = (0); i < ((1ll << (n * n))); i++) {
    tmp = 0;
    cnt = 0;
    for (int j = (0); j < (n * n); j++)
      if ((1ll << (j)) & i) tmp += a[j], cnt++;
    if (cnt > 4) continue;
    M[cnt][tmp] = 1;
  }
  s /= n;
  dfs(1, 1);
  return 0;
}
