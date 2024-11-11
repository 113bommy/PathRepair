#include <bits/stdc++.h>
using namespace std;
const long long N = 1000100;
const long long MOD = 1e9 + 7;
long long n, k, v[N], use[N], in[N];
template <class T>
ostream& operator<<(ostream& out, vector<T> v) {
  out << v.size() << '\n';
  for (auto e : v) out << e << ' ';
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ' ' << p.second << ')';
}
void dfs(long long node) {
  use[node] = 1;
  if (!use[v[node]]) dfs(v[node]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  memset(v, -1, sizeof v);
  v[0] = 0;
  for (long long i = 1; i < n; i++) {
    v[i] = (i * k) % n;
    in[(i * k) % n] = 1;
  }
  long long ans = 1;
  for (long long i = 1; i < n; i++)
    if (v[i] != -1 && in[i] == 0) {
      dfs(i);
      ans = (ans * n) % MOD;
    }
  for (long long i = 1; i < n; i++)
    if (!use[i]) {
      dfs(i);
      ans = (ans * n) % MOD;
    }
  if (k == 1)
    cout << (ans * n) % MOD << '\n';
  else
    cout << ans << '\n';
}
