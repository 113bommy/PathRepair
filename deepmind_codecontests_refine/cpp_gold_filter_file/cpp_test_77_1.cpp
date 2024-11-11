#include <bits/stdc++.h>
using namespace std;
long long n, t, ans, i, j, m, k, a, b, z, voly, c, s[1000 * 1000 + 1],
    parent[1000 * 1000 + 1], used[1000 * 1000 + 1];
vector<long long> v;
void make_set(int v) {
  parent[v] = v;
  s[v] = 1;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (s[a] < s[b]) swap(a, b);
    parent[b] = a;
    s[a] += s[b];
  }
}
signed main() {
  cin >> n >> m;
  for (j = 1; j <= n * m; j++) {
    make_set(j);
    used[j] = 0;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> c;
      if (c % 2 == 0) {
        union_sets((i - 1) * m + j, (i - 1) * m + j - 1);
      }
      c = c / 2;
      if (c % 2 == 0) {
        union_sets((i - 1) * m + j, (i)*m + j);
      }
    }
  }
  for (j = 1; j <= n * m; j++) {
    c = find_set(j);
    if (used[c] == 0) {
      v.push_back(s[c]);
      used[c] = 1;
    }
  }
  sort(v.begin(), v.end());
  for (j = 1; j <= v.size(); j++) {
    cout << v[v.size() - j] << " ";
  }
}
