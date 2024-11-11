#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 234;
const long long mod = 1e9 + 7;
vector<int> v[N];
map<int, int> m;
int x[N / 2], y[N / 2], cnt = 0;
bool mark[N];
long long pow2(long long l, long long r) {
  if (!r) return 1;
  if (r == 1) return l;
  long long o = pow2((l * l) % mod, r / 2);
  return (o * (r % 2 ? l : 1)) % mod;
}
bool dfs(int x, int par) {
  cnt++;
  bool flag = false;
  mark[x] = true;
  for (auto u : v[x])
    if (u != par) {
      if (mark[u])
        flag = true;
      else
        flag |= dfs(u, x);
    }
  return flag;
}
void push(int x) {
  if (m.find(x) == m.end()) m[x] = cnt++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    push(x[i]);
    push(y[i]);
  }
  for (int i = 0; i < n; i++) x[i] = m[x[i]], y[i] = m[y[i]];
  for (int i = 0; i < n; i++) {
    v[x[i]].push_back(y[i] + 2 * n);
    v[y[i] + 2 * n].push_back(x[i]);
  }
  long long ans = 1;
  for (int i = 0; i < n; i++)
    if (!mark[x[i]]) {
      cnt = 0;
      bool has = dfs(x[i], -1);
      ans = (ans * ((pow2(2, cnt) - (!has ? 1 : 0) + mod) % mod)) % mod;
    }
  cout << ans << endl;
  return 0;
}
