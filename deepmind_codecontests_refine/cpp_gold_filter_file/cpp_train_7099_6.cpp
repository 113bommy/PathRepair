#include <bits/stdc++.h>
using namespace std;
int parent[201], siize[201];
int find_set(int s) {
  if (s == parent[s]) return s;
  return parent[s] = find_set(parent[s]);
}
void merge(int u, int v) {
  u = find_set(u);
  v = find_set(v);
  if (u != v) {
    if (siize[u] < siize[v]) swap(u, v);
    parent[v] = u;
    siize[u] += siize[v];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int tc;
  cin >> tc;
  for (int sc = 1; sc < tc + 1; sc++) {
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++) parent[i] = i, siize[i] = 1;
    for (int i = 1; i < n + 1; i++) {
      int num;
      cin >> num;
      merge(i, num);
    }
    for (int i = 1; i < n + 1; i++) {
      cout << siize[find_set(i)] << " ";
    }
    cout << endl;
  }
  return 0;
}
