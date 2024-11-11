#include <bits/stdc++.h>
using namespace std;
inline int nxt() {
  int first;
  scanf("%d", &first);
  return first;
}
const int N = 1111;
vector<int> a[N];
int color[N];
int dfs(int v, int col) {
  color[v] = col;
  int result = 0;
  for (int first : a[v]) {
    if (color[first]) {
      assert(color[first] == col);
      continue;
    }
    result += dfs(first, col) + 1;
  }
  return result;
}
int main() {
  int n = nxt(), m = nxt();
  int k = nxt();
  vector<int> capitals(k);
  for (int i = 0; i < k; ++i) {
    capitals[i] = nxt() - 1;
  }
  for (int i = 0; i < m; ++i) {
    int u = nxt() - 1, v = nxt() - 1;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  vector<int> eds(k);
  for (int i = 0; i < k; ++i) {
    eds[i] = dfs(capitals[i], i + 1);
  }
  vector<int> szs(k);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (color[j] == color[capitals[i]]) {
        ++szs[i];
      }
    }
  }
  int ans = 0;
  int edges = m;
  int verts = n;
  for (int i = 0; i < k; ++i) {
    ans += szs[i] * (szs[i] - 1) / 2 - eds[i];
    verts -= szs[i];
    edges -= eds[i];
  }
  ans += verts * (verts - 1) / 2 - edges;
  ans += *max_element((szs).begin(), (szs).end()) * verts;
  printf("%d\n", ans);
  return 0;
}
