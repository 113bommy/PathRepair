#include <bits/stdc++.h>
using namespace std;
const int N = 5e5, M = 1e9 + 7;
long long c[N];
int par[N], sz[N], n, m, k;
int get(int u) { return par[u] == u ? u : par[u] = get(par[u]); }
map<long long, vector<pair<int, int>>> mp;
void add(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}
int power(int base, int to) {
  int ret = 1;
  while (to) {
    if (to & 1) ret = ret * 1LL * base % M;
    to >>= 1;
    base = base * 1LL * base % M;
  }
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%lld", c + i);
  for (int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
  for (int i = 0, a, b; i < m; i++) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    mp[c[a] ^ c[b]].push_back({a, b});
  }
  int ans = power(2, n) * (((1LL << k) - mp.size()) % M) % M;
  for (auto i : mp) {
    vector<int> temp;
    for (auto j : i.second) {
      temp.push_back(j.first);
      temp.push_back(j.second);
      int x = get(j.first), y = get(j.second);
      if (x != y) {
        sz[x] += sz[y];
        par[y] = x;
      }
    }
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    int sum = 0, temp1 = 1;
    for (auto j : temp)
      if (j == par[j]) {
        add(temp1, temp1);
        sum += sz[j];
      }
    for (auto j : i.second) {
      int x = j.first, y = j.second;
      par[x] = x, par[y] = y, sz[x] = sz[y] = 1;
    }
    add(ans, temp1 * 1LL * power(2, n - sum) % M);
  }
  printf("%d\n", ans);
}
