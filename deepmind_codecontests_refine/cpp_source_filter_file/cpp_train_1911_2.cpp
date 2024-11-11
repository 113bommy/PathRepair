#include <bits/stdc++.h>
using namespace std;
const int N = 250000 + 10;
int n, a[N * 2], t[N * 2];
void build(const int &x, const int &l, const int &r) {
  if (l == r) {
    t[x] = l;
    return;
  }
  int m = (l + r) / 2;
  build(x * 2, l, m);
  build(x * 2 + 1, m + 1, r);
  int L = t[x * 2], R = t[x * 2 + 1];
  if (L - a[L] < R - a[R])
    t[x] = L;
  else
    t[x] = R;
}
int get(const int &x, const int &l, const int &r, const int &u, const int &v) {
  if (r < u || v < l) return 0;
  if (u <= l && r <= v) return t[x];
  int m = (l + r) / 2;
  int L = get(x * 2, l, m, u, v), R = get(x * 2 + 1, m + 1, r, u, v);
  if (L - a[L] < R - a[R]) return L;
  return R;
}
vector<int> adj[N * 2], path;
long long res = 0;
void dfs(const int &u) {
  path.push_back(u);
  if (u > n) {
    int low = 0, high = path.size() - 1;
    while (low < high) {
      int mid = (low + high + 1) / 2;
      if (u - n + 1 < path[mid] - a[path[mid]])
        high = mid - 1;
      else
        low = mid;
    }
    res += path.size() - low;
  }
  for (__typeof((adj[u]).begin()) i = (adj[u]).begin(); i != (adj[u]).end();
       ++i)
    dfs(*i);
  path.pop_back();
}
int main(int ac, char **av) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i] = min(a[i], n - 1);
    a[i + n] = a[i];
  }
  a[0] = -1e9;
  a[1] = 1e9;
  build(1, 1, n * 2);
  for (int i = 2; i <= n * 2; ++i) {
    adj[get(1, 1, n * 2, i - a[i], i)].push_back(i);
  }
  dfs(1);
  printf("%lld\n", res);
  return 0;
}
