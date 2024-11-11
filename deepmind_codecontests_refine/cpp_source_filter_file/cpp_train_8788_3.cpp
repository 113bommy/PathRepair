#include <bits/stdc++.h>
using namespace std;
const int MAX = 500020;
const long long MOD = (int)1e9 + 7;
const int INF = 1e9;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-7;
struct DSU {
  int n;
  vector<int> parent, size;
  DSU(int n) {
    this->n = n;
    parent.assign(n + 1, 0);
    size.assign(n + 1, 1);
    for (int i = 0; i <= n; i++) parent[i] = i;
  }
  int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
  void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
  int sz(int v) { return size[find(v)]; }
};
int find(vector<int>& ind, int idx) {
  int l = 0, r = ind.size() - 1, res = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ind[mid] <= idx) {
      res = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return res + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> sz = {0};
  vector<int> ind = {0};
  int total = 1;
  for (int i = 0; i < (int)k; i++) {
    int s;
    cin >> s;
    total += s;
    ind.push_back(total);
    sz.push_back(s);
  }
  DSU dsu = DSU(n + 2);
  vector<vector<long long> > d(k + 1, vector<long long>(k + 1, LLINF));
  bool win = true;
  for (int i = 0; i < (int)m; i++) {
    long long a, b, w;
    cin >> a >> b >> w;
    int ta = find(ind, a), tb = find(ind, b);
    if (w == 0) {
      dsu.join(a, b);
    }
    d[ta][tb] = min(d[ta][tb], w);
    d[tb][ta] = min(d[tb][ta], w);
  }
  for (int i = 1; i <= n - 1; i++) {
    int t1 = find(ind, i), t2 = find(ind, i + 1);
    if (t1 == t2 and dsu.find(t1) != dsu.find(t2)) win = false;
  }
  if (!win) {
    cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
    for (int c = 1; c <= k; c++) {
      for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
          if (i == j) continue;
          d[i][j] = min(d[i][j], d[i][c] + d[c][j]);
        }
      }
    }
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= k; j++) {
        if (i == j)
          cout << 0 << " ";
        else
          cout << (d[i][j] >= INF ? -1 : d[i][j]) << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
