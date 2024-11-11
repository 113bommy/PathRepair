#include <bits/stdc++.h>
using namespace std;
int x[200005], y[200005];
int sgn[200005];
int par[200005];
vector<int> g[200005];
bool check(int a, int b, long long th) {
  int icap = x[a] + x[b];
  int jcap = y[a] + y[b];
  long long z = 1LL * icap * icap + 1LL * jcap * jcap;
  return (z <= th);
}
bool checkR(int a, int b, long long th) {
  int icap = x[a] - x[b];
  int jcap = y[a] - y[b];
  long long z = 1LL * icap * icap + 1LL * jcap * jcap;
  return (z <= th);
}
void dfs(int x, int p) {
  sgn[x] *= sgn[p];
  for (auto i : g[x]) {
    if (i != p) dfs(i, x);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> x[i] >> y[i];
  }
  vector<int> v;
  for (int i = 1; i < n + 1; i++) {
    v.push_back(i);
  }
  for (int i = 0; i < 200005; i++) {
    sgn[i] = 1;
  }
  int id = n;
  while (v.size() > 2) {
    int u[3];
    u[0] = v.back();
    v.pop_back();
    u[1] = v.back();
    v.pop_back();
    u[2] = v.back();
    v.pop_back();
    bool flag = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 3; j++) {
        if (check(u[i], u[j], 1e12)) {
          par[u[i]] = par[u[j]] = ++id;
          g[id].push_back(u[i]);
          g[id].push_back(u[j]);
          x[id] = x[u[i]] + x[u[j]];
          y[id] = y[u[i]] + y[u[j]];
          v.push_back(id);
          for (int k = 0; k < 3; k++) {
            if (k != i && k != j) v.push_back(u[k]);
          }
          flag = 1;
        } else if (checkR(u[i], u[j], 1e12)) {
          par[u[i]] = par[u[j]] = ++id;
          g[id].push_back(u[i]);
          g[id].push_back(u[j]);
          x[id] = x[u[i]] - x[u[j]];
          y[id] = y[u[i]] - y[u[j]];
          sgn[u[j]] = -1;
          v.push_back(id);
          for (int k = 0; k < 3; k++) {
            if (k != i && k != j) v.push_back(u[k]);
          }
          flag = 1;
        }
        if (flag == 1) break;
      }
      if (flag) break;
    }
    assert(flag);
  }
  ++id;
  g[id].push_back(v[0]);
  g[id].push_back(v[1]);
  if (check(v[0], v[1], 2.25 * 1e12) == 0) {
    sgn[v[1]] = -1;
  }
  dfs(id, 0);
  int ansx = 0, ansy = 0;
  for (int i = 1; i < n + 1; i++) {
    ansx += x[i] * sgn[i];
    ansy += y[i] * sgn[i];
    cout << sgn[i] << " ";
  }
}
