#include <bits/stdc++.h>
using namespace std;
int p[200];
int r[200];
bool was[200];
bool good[200];
int getparent(int u) {
  if (p[u] == u) return u;
  p[u] = getparent(p[u]);
  return p[u];
}
void unite(int a, int b) {
  a = getparent(a);
  b = getparent(b);
  if (a == b) return;
  if (r[a] < r[b]) swap(a, b);
  if (r[a] == r[b]) r[a]++;
  p[b] = a;
}
vector<int> q[100];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n + m; i++)
    p[i] = i, good[i] = false, was[i] = false, r[i] = 0;
  for (int j = 0; j < n; j++) {
    j = j;
    for (int i = j % m;; i = (i + n) % m) {
      if (was[i]) break;
      unite(j, n + i), was[i] = true;
      cerr << j << " " << i << endl;
    }
    fill(was, was + n, false);
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    good[getparent(n + x)] = true;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    good[getparent(n + x)] = true;
  }
  for (int i = 0; i < n + m; i++) {
    if (!good[getparent(i)]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
