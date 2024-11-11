#include <bits/stdc++.h>
using namespace std;
int head[5005 * 5005 / 2], nxt[5005 * 5005 / 2], sz[5005], lst = 1;
pair<int, int> to[5005 * 5005 / 2];
int arr[5005];
int cnt = 0;
int n, k;
void add_edge(int f, pair<int, int> p) {
  nxt[lst] = head[f];
  head[f] = lst;
  sz[f]++;
  to[lst++] = p;
}
struct disjoint_set {
  int par[5005], in[5005], deg[5005], lst;
  bool vis[5005];
  disjoint_set() {
    for (int i = 0; i <= 5005; i++) par[i] = i;
    lst = 0;
  }
  void reset() {
    for (int i = 0; i < lst; i++)
      par[in[i]] = in[i], vis[in[i]] = 0, deg[in[i]] = 0;
    lst = 0;
  }
  int find_par(int cur) {
    if (cur != par[cur]) return par[cur] = find_par(par[cur]);
    return par[cur];
  }
  int join(int x, int y) {
    x = find_par(x), y = find_par(y);
    if (x == y) return 0;
    if (deg[x] == deg[y]) deg[x]++;
    if (deg[x] < deg[y]) swap(x, y);
    par[y] = x;
    if (!vis[x]) in[lst++] = x, vis[x] = 1;
    if (!vis[y]) in[lst++] = y, vis[y] = 1;
    return 1;
  }
} dsu;
void check(int d) {
  for (int i = head[d]; i; i = nxt[i]) {
    cnt += dsu.join(to[i].first, to[i].second);
    if (cnt > k) return;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  if (k + 1 >= n) {
    cout << "1\n";
    return 0;
  }
  int mx = 0;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n, greater<int>());
  mx = arr[0];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) add_edge(arr[i] - arr[j], make_pair(i, j));
  for (int i = n - k; i <= mx + 1; i++) {
    cnt = 0;
    dsu.reset();
    for (int j = i; j <= mx + 1; j += i) {
      if (sz[j] > 10) {
        cnt = 100;
        break;
      }
      check(j);
      if (cnt > k) break;
    }
    if (cnt <= k) {
      cout << i << "\n";
      return 0;
    }
  }
}
