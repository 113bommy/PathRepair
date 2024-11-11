#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
template <class T, class U>
inline void checkmin(T &x, U y) {
  if (y < x) x = y;
}
template <class T, class U>
inline void checkmax(T &x, U y) {
  if (y > x) x = y;
}
template <class T, class U>
inline bool ifmin(T &x, U y) {
  if (y < x) return x = y, true;
  return false;
}
template <class T, class U>
inline bool ifmax(T &x, U y) {
  if (y > x) return x = y, true;
  return false;
}
template <class T>
inline void sort(T &a) {
  sort(a.begin(), a.end());
}
template <class T>
inline void rsort(T &a) {
  sort(a.rbegin(), a.rend());
}
template <class T>
inline void reverse(T &a) {
  reverse(a.begin(), a.end());
}
template <class T>
inline istream &operator>>(istream &stream, vector<T> &a) {
  for (auto &i : a) stream >> i;
  return stream;
}
vector<long long> color;
vector<vector<int>> G, tree;
vector<long long> c2, c1;
bool flag = false;
void orient(int v, int p = -1) {
  for (auto i : G[v])
    if (i != p) {
      tree[v].push_back(i);
      orient(i, v);
    }
}
void dfscount(int v) {
  c2[v] = color[v] == 2;
  c1[v] = color[v] == 1;
  for (auto i : tree[v]) {
    dfscount(i);
    c2[v] += c2[i];
    c1[v] += c1[i];
  }
}
long long dfsadd(int v, long long c) {
  long long ans = 0;
  if (c2[v] == c && c1[v] == 0) ++ans;
  if (c2[v] < c && c2[v] > 0 && c1[v] > 0) flag = true;
  for (auto i : tree[v]) ans += dfsadd(i, c);
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  srand(85453532);
  long long n;
  cin >> n;
  color = vector<long long>(n);
  cin >> color;
  G = tree = vector<vector<int>>(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  long long head = -1;
  for (int i = 0; i < n; ++i)
    if (color[i] == 1) head = i;
  orient(head);
  c1 = c2 = vector<long long>(n);
  long long ans = 0;
  for (auto i : tree[head]) {
    dfscount(i);
    flag = false;
    long long add = dfsadd(i, c2[i]);
    if (ans > 0 && add > 0 || flag) {
      ans = 0;
      break;
    }
    ans += dfsadd(i, c2[i]);
  }
  cout << ans;
  return 0;
}
