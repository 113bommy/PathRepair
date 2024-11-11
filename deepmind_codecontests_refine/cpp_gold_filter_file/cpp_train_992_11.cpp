#include <bits/stdc++.h>
using namespace std;
long long n = 2 * 1e5 + 1;
long long root = 0;
vector<vector<long long>> adj(n);
vector<long long> c, vi(n);
vector<bool> visited(n);
void dfs(long long s, long long anc) {
  if (visited[s]) return;
  visited[s] = true;
  for (auto u : adj[s]) {
    if (visited[u] == true && u != anc && u != s && vi[s] == 0) {
      c.push_back(u);
      vi[u] = 1;
    }
    dfs(u, s);
  }
}
int main() {
  long long m;
  cin >> m;
  long long res = -1;
  vector<long long> a(m);
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
    adj[a[i]].push_back(i + 1);
    adj[i + 1].push_back(a[i]);
    if (a[i] == i + 1 && root == 0) root = a[i];
  }
  for (long long i = 1; i < m + 1; i++) {
    if (visited[i] == false) {
      dfs(i, -1);
      res++;
    }
  }
  if (res == 0 && root == 0) {
    res++;
    a[c[0] - 1] = c[0];
  } else if (res > 0 && root == 0) {
    res++;
    root = c[0];
    for (long long i = 0; i < c.size(); i++) a[c[i] - 1] = root;
  } else if (res > 0 && root > 0) {
    for (long long i = 0; i < m; i++) {
      if (a[i] == i + 1 && a[i] != root) a[i] = root;
    }
    for (long long i = 0; i < c.size(); i++) a[c[i] - 1] = root;
  }
  cout << res << endl;
  for (auto i = a.begin(); i != a.end(); i++) {
    cout << *i << " ";
  }
  cout << "\n";
  ;
  return 0;
}
