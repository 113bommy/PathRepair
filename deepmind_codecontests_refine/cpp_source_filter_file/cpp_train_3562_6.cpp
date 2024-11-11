#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const int INF = 2e9;
const int MOD = 1e6 + 3;
int n, k;
int sets[N][2];
string s;
int parent[N], sz[N], xr[N];
bool isfixed[N];
int cnt[N][2];
int cont[N];
int ans;
void make(int x) {
  parent[x] = x;
  sz[x] = 1;
  xr[x] = 0;
  isfixed[x] = false;
  cnt[x][0] = 1;
  cnt[x][1] = 0;
  cont[x] = 0;
}
pair<int, int> find(int v) {
  if (parent[v] == v) return make_pair(v, xr[v]);
  pair<int, int> pr = find(parent[v]);
  pair<int, int> res = make_pair(pr.first, pr.second ^ xr[v]);
  parent[v] = pr.first;
  xr[v] ^= pr.second ^ xr[pr.first];
  return res;
}
void merge(int v, int u, int x) {
  pair<int, int> prv = find(v);
  pair<int, int> pru = find(u);
  int valv = prv.second, valu = pru.second;
  v = prv.first;
  u = pru.first;
  if (v == u) return;
  if (sz[v] > sz[u]) {
    swap(v, u);
    swap(valv, valu);
  }
  ans -= cont[v];
  ans -= cont[u];
  if ((valv ^ valu) != x) {
    if (!isfixed[v]) {
      swap(cnt[v][0], cnt[v][1]);
      xr[v] ^= 1;
    } else {
      swap(cnt[u][0], cnt[u][1]);
      xr[u] ^= 1;
    }
  }
  parent[v] = u;
  xr[v] ^= xr[u];
  sz[u] += sz[v];
  cnt[u][0] += cnt[v][0];
  cnt[u][1] += cnt[v][1];
  isfixed[u] |= isfixed[v];
  if (!isfixed[u] && cnt[u][0] < cnt[u][1]) {
    swap(cnt[u][0], cnt[u][1]);
    xr[u] ^= 1;
  }
  cont[u] = cnt[u][1];
  ans += cont[u];
}
void fix(int v, int x) {
  pair<int, int> pr = find(v);
  v = pr.first;
  int val = pr.second;
  if (val != x) {
    swap(cnt[v][0], cnt[v][1]);
    ans -= cont[v];
    cont[v] = cnt[v][1];
    ans += cont[v];
    xr[v] ^= x;
  }
  isfixed[v] = true;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) sets[i][0] = sets[i][1] = -1;
  cin >> s;
  for (int i = 1; i <= k; i++) {
    int sz;
    scanf("%d", &sz);
    while (sz--) {
      int x;
      scanf("%d", &x);
      if (sets[x][0] == -1)
        sets[x][0] = i;
      else
        sets[x][1] = i;
    }
  }
  for (int i = 1; i <= k; i++) make(i);
  ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = s[i - 1] - '0';
    x ^= 1;
    if (sets[i][1] == -1) {
      if (sets[i][0] != -1) fix(sets[i][0], x);
    } else {
      merge(sets[i][0], sets[i][1], x);
    }
    printf("%d ", ans);
  }
  return 0;
}
