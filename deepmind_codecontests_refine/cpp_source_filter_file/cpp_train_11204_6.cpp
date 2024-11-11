#include <bits/stdc++.h>
using namespace std;
int n, parent[300001], size[300001];
void make_set(int v) {
  parent[v] = v;
  size[v] = 1;
}
int find_set(int v) {
  if (parent[v] == v) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  if (size[a] == 0 || size[b] == 0) return;
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    parent[b] = a;
  }
}
int main() {
  cin >> n;
  cout << "1 ";
  for (int x, i = 1; i <= n; i++) {
    scanf("%d", &x);
    make_set(x);
    union_sets(x, x + 1);
    union_sets(x - 1, x);
    printf("%d ", &i + 1 - size[find_set(n)]);
  }
  return 0;
}
