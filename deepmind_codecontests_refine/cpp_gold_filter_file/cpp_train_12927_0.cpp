#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <class T>
ostream& prnt(ostream& out, T v) {
  out << v.size() << '\n';
  for (auto e : v) out << e << ' ';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<T> v) {
  return prnt(out, v);
}
template <class T>
ostream& operator<<(ostream& out, set<T> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ' ' << p.second << ')';
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const long long N = 1010;
const long long MOD = 2520;
const long long M = MOD + 10;
long long n, w[N][M], use[N][M], ans[N][M], m[N], k[N], take, q, a, b, res_ans;
vector<pair<long long, long long> > cache;
bitset<N> v;
void dfs(long long node, long long col) {
  col %= MOD;
  if (col < 0) col += MOD;
  if (ans[node][col] != -1) {
    res_ans = ans[node][col];
    return;
  }
  if (use[node][col]) {
    v[node] = 1;
    use[node][col] = 0;
    return;
  }
  cache.push_back({node, col});
  use[node][col] = 1;
  long long nn = w[node][col % m[node]];
  dfs(nn, col + k[nn]);
  if (res_ans) return;
  if (use[node][col] == 0) {
    take = 0;
  } else if (take) {
    v[node] = 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> k[i];
    k[i] %= MOD;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> m[i];
    for (long long j = 0; j < m[i]; j++) cin >> w[i][j];
  }
  memset(ans, -1, sizeof ans);
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j < MOD; j++)
      if (ans[i][j] == -1) {
        v.reset();
        cache.clear();
        take = 1;
        res_ans = 0;
        dfs(i, j);
        if (res_ans)
          ans[i][j] = res_ans;
        else
          ans[i][j] = v.count();
        for (auto ii : cache) {
          ans[ii.first][ii.second] = ans[i][j];
          use[ii.first][ii.second] = 0;
        }
      }
  cin >> q;
  for (long long i = 1; i <= q; i++) {
    cin >> a >> b;
    b += k[a];
    b %= MOD;
    if (b < 0) b += MOD;
    cout << ans[a][b] << '\n';
  }
}
