#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> s_tree;
int find(int a) {
  if (parent[a] != a) {
    return parent[a] = find(parent[a]);
  }
  return a;
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (s_tree[a] < s_tree[b]) {
    parent[a] = b;
    s_tree[b] += s_tree[a];
  } else {
    parent[b] = a;
    s_tree[a] += s_tree[b];
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  vector<int> perm(n);
  vector<int> inverse(n);
  parent = vector<int>(n);
  s_tree = vector<int>(n, 1);
  vector<int> indices(n);
  vector<int> algo(n);
  for (int i = 0; i < n; ++i) {
    cin >> perm[i];
    perm[i]--;
    inverse[perm[i]] = i;
    parent[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    merge(a - 1, b - 1);
  }
  vector<int> next(n, -1);
  vector<int> follow(n);
  for (int i = n - 1; i >= 0; --i) {
    int a = find(i);
    follow[i] = next[a];
    next[a] = i;
  }
  vector<int> sol(n);
  for (int i = n - 1; i >= 0; --i) {
    int a = find(inverse[i]);
    sol[next[a]] = i;
    next[a] = follow[next[a]];
  }
  for (int i = 0; i < n; ++i) {
    cout << sol[i] + 1 << ((i == n - 1) ? '\n' : ' ');
  }
}
