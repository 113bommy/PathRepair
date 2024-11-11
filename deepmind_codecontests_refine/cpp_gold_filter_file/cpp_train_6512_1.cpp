#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
long long n, u, v, sz[N], M, phi, s, w, local[N], local2[N];
long long ans;
vector<pair<int, int>> node[N];
map<int, int> mp;
bool mark[N], fin;
void dfs(int v, int p) {
  sz[v] = 1;
  for (auto i : node[v]) {
    if (!mark[i.first] && i.first != p) {
      dfs(i.first, v);
      sz[v] += sz[i.first];
    }
  }
}
long long mypow(long long a, long long b) {
  return b ? (mypow(a * a % M, b >> 1) * ((b & 1) ? a : 1)) % M : 1;
}
void get(int v, int p, int now, int h, int keep) {
  if (now == 0 && keep) ans++;
  ans += mp[((M - now) * local[h]) % M];
  for (auto i : node[v])
    if (!mark[i.first] && i.first != p)
      get(i.first, v, (now * 1ll * 10 + i.second) % M, h + 1, keep);
}
void add(int v, int p, int now, int h) {
  mp[now]++;
  for (auto i : node[v])
    if (!mark[i.first] && i.first != p)
      add(i.first, v, (now + i.second * 1ll * local2[h]) % M, h + 1);
}
void solve(int v) {
  dfs(v, v);
  s = sz[v];
  int f = -1;
  int x = v;
  while (true) {
    fin = true;
    for (auto i : node[x]) {
      if (!mark[i.first] && sz[i.first] > s / 2 && i.first != f) {
        fin = false;
        f = x;
        x = i.first;
        break;
      }
    }
    if (fin) break;
  }
  mark[x] = true;
  for (auto i : node[x]) {
    if (!mark[i.first]) {
      get(i.first, x, i.second, 1, 1);
      add(i.first, x, i.second, 1);
    }
  }
  ans += mp[0];
  mp.clear();
  for (int i = (int)node[x].size() - 1; i >= 0; i--) {
    if (!mark[node[x][i].first]) {
      get(node[x][i].first, x, node[x][i].second, 1, 0);
      add(node[x][i].first, x, node[x][i].second, 1);
    }
  }
  mp.clear();
  for (auto i : node[x])
    if (!mark[i.first]) solve(i.first);
}
int fi(int num) {
  double ph = num;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      ph *= (i - 1);
      ph /= i;
      while (num % i == 0) num /= i;
    }
  }
  if (num > 1) {
    ph *= (num - 1);
    ph /= num;
  }
  return ph;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> M;
  phi = fi(M);
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> w;
    if (w >= M) w %= M;
    node[u].push_back({v, w});
    node[v].push_back({u, w});
  }
  local[0] = 1;
  local2[0] = 1;
  local[1] = mypow(10, phi - 1);
  local2[1] = 10 % M;
  for (int i = 2; i < N; i++) {
    local[i] = (local[i - 1] * 1ll * local[1]) % M;
    local2[i] = (local2[i - 1] * 1ll * 10) % M;
  }
  solve(0);
  cout << ans << '\n';
  return 0;
}
