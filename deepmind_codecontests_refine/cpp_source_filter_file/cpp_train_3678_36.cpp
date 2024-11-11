#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int HP = 727;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const int N = 1e5 + 20;
long long dsu[N], n, m, k, ans = 1;
set<int> s;
long long powmod(long long x, long long y, long long MODD = MOD) {
  if (y == 0) return 1LL;
  long long tmp = powmod(x, y / 2, MODD);
  tmp = ((tmp) * (tmp)) % MODD;
  return (tmp * (y % 2 ? (x % MODD) : 1LL)) % MODD;
}
int find(int v) { return dsu[v] < 0 ? v : (dsu[v] = find(dsu[v])); }
void merge(int v, int u) {
  if ((v = find(v)) == (u = find(u))) return;
  if (dsu[v] > dsu[u]) swap(v, u);
  dsu[v] += dsu[u];
  dsu[u] = v;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  memset(dsu, -1, sizeof dsu);
  cin >> n >> m >> k;
  for (int i = 0, v, u; i < m; i++) {
    cin >> v >> u;
    merge(v, u);
  }
  for (int i = 1; i <= n; i++) s.insert(find(i));
  for (int v : s) ans = (ans * -dsu[v]) % k;
  if (s.size() == 1)
    cout << 1 << endl;
  else
    cout << (ans * powmod(n, s.size() - 2, k)) % k << endl;
}
