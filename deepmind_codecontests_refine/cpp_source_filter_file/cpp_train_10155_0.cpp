#include <bits/stdc++.h>
using namespace std;
vector<int> adj[500000];
int centroid[500000];
int sz[500000];
int maxi[500000];
int papa[500000];
bool ok(int c, int i, int m) {
  int mx = max(sz[i] - sz[c], m);
  return (2 * mx <= sz[i]);
}
void gen(int i, int p) {
  sz[i] = 1;
  papa[i] = p;
  bool flag = false;
  pair<int, int> mx = make_pair(-1, -1);
  for (auto j : adj[i])
    if (j != p) {
      flag = true;
      gen(j, i);
      sz[i] += sz[j];
      mx = max(mx, make_pair(sz[j], j));
    }
  maxi[i] = mx.first;
  if (!flag) {
    centroid[i] = i;
    return;
  }
  int c = centroid[mx.second];
  centroid[i] = c;
  while (c != i) {
    if (ok(c, i, maxi[mx.second])) break;
    c = papa[c];
  }
  centroid[i] = c;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[i].push_back(p);
    adj[p].push_back(i);
  }
  gen(1, -1);
  while (q--) {
    int x;
    cin >> x;
    cout << centroid[x] << endl;
  }
  return 0;
}
