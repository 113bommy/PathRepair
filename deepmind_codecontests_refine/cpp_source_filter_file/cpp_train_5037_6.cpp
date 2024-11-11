#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e5 + 10, D = 313, mod = 1e9 + 7;
long long hsh[maxn], n, ht, ans, tz, p[maxn];
string t, s[maxn];
vector<pair<int, int> > nei[maxn];
void find_p() {
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = (p[i - 1] * D) % mod;
}
long long get_hash(int st, int en) {
  return ((hsh[en] - hsh[st] * p[en - st]) % mod + mod) % mod;
}
void st_hash() {
  for (int i = 0; i < tz; i++) hsh[i + 1] = ((hsh[i] * D) + t[i]) % mod;
  ht = hsh[tz];
  memset(hsh, 0, sizeof hsh);
}
void dfs(int v, int par, int ptr) {
  for (auto u : nei[v])
    if (u.first != par) {
      for (auto i : s[u.second]) {
        hsh[ptr + 1] = ((hsh[ptr] * D) + i) % mod;
        ptr++;
        if (ptr - tz >= 0 && get_hash(ptr - tz, ptr) == ht) ans++;
      }
      dfs(u.first, v, ptr);
      ptr -= (int)s[u.second].size();
    }
}
int main() {
  ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  int a;
  string b;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    a--;
    s[i] = b;
    nei[i].push_back({a, i});
    nei[a].push_back({i, i});
  }
  cin >> t;
  tz = (int)t.size();
  find_p();
  st_hash();
  dfs(0, -1, 0);
  cout << ans << endl;
}
