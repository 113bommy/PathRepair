#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<int> p;
  vector<int> rnk;
  DSU() {}
  DSU(int n) {
    p.resize(n);
    rnk.resize(n);
    fill_n(rnk.begin(), n, 1);
    int k = 0;
    generate_n(p.begin(), n, [&k]() { return k++; });
  }
  void make_set(int x) {
    while (p.size() <= x) {
      p.push_back(p.size());
    }
  }
  int find_set(int x) {
    if (x == p[x]) return x;
    p[x] = find_set(p[x]);
    return p[x];
  }
  void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (rnk[x] > rnk[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rnk[x] == rnk[y]) {
        ++rnk[y];
      }
    }
  }
};
int a[100013];
int main() {
  DSU dsu(1000013);
  int n, m;
  cin >> n >> m;
  dsu.make_set(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[v]++;
    a[u]++;
    if (a[u] > 2 || a[v] > 2) {
      cout << "NO";
      return 0;
    }
    u = dsu.find_set(u);
    v = dsu.find_set(v);
    if ((u == v) && ((i != n) || (i != m))) {
      cout << "NO";
      return 0;
    } else {
      dsu.union_set(u, v);
    }
  }
  cout << "YES" << endl << n - m << endl;
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= 2; k++) {
      for (int j = i + 1; j <= n; j++) {
        int x = dsu.find_set(i), y = dsu.find_set(j);
        if ((x != y) && (a[i] < 2) && (a[j] < 2)) {
          dsu.union_set(x, y);
          a[i]++;
          a[j]++;
          cout << i << " " << j << endl;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    while (a[i] < 2) {
      cout << i << " ";
      a[i]++;
    }
  }
}
