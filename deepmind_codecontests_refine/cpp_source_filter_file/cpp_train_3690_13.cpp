#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 4;
int size[N];
int parent[N];
int arr[N];
int n;
int m;
struct edge {
  int from;
  int to;
  int value;
  edge(int f, int t, int v) {
    from = f;
    to = t;
    value = v;
  }
  bool operator<(const edge &b) const { return value > b.value; }
};
vector<edge> v;
int find(int node) {
  return parent[node] = (node == parent[node]) ? node : find(parent[node]);
}
long long join(int a, int b) {
  int x = find(a);
  int y = find(b);
  if (x == y) return 0;
  int ret = 1LL * size[x] * size[y];
  if (size[x] >= size[y]) {
    parent[y] = x;
    size[x] += size[y];
  } else {
    parent[x] = y;
    size[y] += size[x];
  }
  return ret;
}
int main(void) {
  scanf("%d%d ", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d ", &arr[i]);
    parent[i] = i;
    size[i] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    v.emplace_back(edge(a, b, min(arr[a], arr[b])));
  }
  sort(v.begin(), v.end());
  long long sum = 0;
  for (edge it : v) {
    sum += join(it.from, it.to) * it.value;
  }
  double ans = sum;
  ans /= n;
  ans /= (n - 1);
  ans += ans;
  cout << ans;
}
