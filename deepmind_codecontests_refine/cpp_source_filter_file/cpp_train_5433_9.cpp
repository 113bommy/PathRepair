#include <bits/stdc++.h>
using namespace std;
int N, M;
signed long long E[51];
template <int um>
class UF {
 public:
  vector<int> par, rank, cnt;
  UF() {
    par = rank = vector<int>(um, 0);
    cnt = vector<int>(um, 1);
    for (int i = 0; i < um; i++) par[i] = i;
  }
  void reinit() {
    int i;
    for (i = 0; i < (um); i++) rank[i] = 0, cnt[i] = 1, par[i] = i;
  }
  int operator[](int x) {
    return (par[x] == x) ? (x) : (par[x] = operator[](par[x]));
  }
  int count(int x) { return cnt[operator[](x)]; }
  int operator()(int x, int y) {
    if ((x = operator[](x)) == (y = operator[](y))) return x;
    cnt[y] = cnt[x] = cnt[x] + cnt[y];
    if (rank[x] > rank[y]) return par[x] = y;
    rank[x] += rank[x] == rank[y];
    return par[y] = x;
  }
};
UF<41> uf;
int vis[51];
signed long long num[1 << 20];
signed long long F012() { return 1LL << N; }
signed long long F01() {
  int i;
  int mask;
  signed long long ret = 0;
  for (mask = 0; mask < (1 << (min(20, N))); mask++) {
    int ok = 1;
    for (i = 0; i < (min(20, N)); i++)
      if (mask & (1 << i)) {
        if (E[i] & mask) ok = 0;
      }
    num[mask] = ok;
  }
  for (i = 0; i < (20); i++)
    for (mask = 0; mask < (1 << 20); mask++)
      if (mask & (1 << i)) num[mask] += num[mask ^ (1 << i)];
  for (mask = 0; mask < (1 << 20); mask++) {
    int ok = 1;
    signed long long tmask = 0;
    for (i = 0; i < (20); i++)
      if (mask & (1 << i)) {
        if (i + 20 >= N) ok = 0;
        tmask |= E[i + 20];
        if (mask & E[i + 20]) ok = 0;
      }
    if (ok) {
      tmask = ~tmask & ((1 << 20) - 1);
      ret += num[tmask];
    }
  }
  return ret;
}
signed long long F02() {
  int C = 0;
  int i;
  for (i = 0; i < (N); i++)
    if (uf[i] == i) C++;
  return 1LL << C;
}
signed long long F0() {
  int C = 0;
  int i;
  for (i = 0; i < (N); i++)
    if (E[i] == 0) C++;
  return 1LL << C;
}
int dfs(int cur, int pre, int v) {
  if (vis[cur] != -1) return vis[cur] == v;
  vis[cur] = v;
  int ret = 1;
  int i;
  for (i = 0; i < (N); i++)
    if (E[cur] & (1LL << i)) ret &= dfs(i, cur, v ^ 1);
  return ret;
}
signed long long F1() {
  signed long long ret = 1;
  int i;
  memset(vis, 0xff, sizeof(vis));
  for (i = 0; i < (N); i++)
    if (uf[i] == i) {
      if (dfs(i, -1, 0) == 0) return 0;
      ret *= 2;
    }
  return ret;
}
signed long long F() {
  if (M == 0) return 1LL << N;
  return 0;
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> M;
  for (i = 0; i < (M); i++) {
    cin >> x >> y;
    x--, y--;
    uf(x, y);
    E[x] |= 1LL << y;
    E[y] |= 1LL << x;
  }
  signed long long ret = F012() - 2 * F01() - F02() + 2 * F0() + F1() - F();
  cout << ret << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
