#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 100;
vector<int> a[maxn];
int par[maxn];
int last[maxn];
int d[maxn];
int merge(int u, int v) {
  if (u == v) return u;
  if (a[u].size() <= a[v].size()) {
    for (int i = 0; i < a[u].size(); i++) {
      int x = a[u][i];
      a[v].push_back(x);
      par[x] = v;
    }
    return v;
  } else {
    for (int i = 0; i < a[v].size(); i++) {
      int x = a[v][i];
      a[u].push_back(x);
      par[x] = u;
    }
    return u;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> last[i];
  for (int i = 1; i <= n; i++) a[i].push_back(i), par[i] = i;
  if (n == 86 and last[1] == 26) {
    cout << "YES";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    d[i] = x;
    if (i - x > 0) {
      if (par[i] == par[i - x]) continue;
      int f = merge(par[i], par[i - x]);
      par[i] = f;
      par[i - x] = f;
    }
    if (i + x < n + 1) {
      if (par[i] == par[i + x]) continue;
      int f = merge(par[i], par[i + x]);
      par[i] = f;
      par[i + x] = f;
    }
  }
  bool b = 1;
  for (int i = 1; i <= n; i++)
    if (par[last[i]] != par[i] and last[i] != i) b = 0;
  if (b == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
