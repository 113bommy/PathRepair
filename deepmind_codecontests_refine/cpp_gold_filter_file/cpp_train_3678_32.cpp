#include <bits/stdc++.h>
using namespace std;
bool used[100001];
vector<int> g[100001];
int getComponent(int v) {
  if (used[v]) return 0;
  used[v] = true;
  int rest = 0;
  for (int i = 0; i < g[v].size(); i++) {
    if (!used[g[v][i]]) rest += getComponent(g[v][i]);
  }
  return rest + 1;
}
int n, m;
long long k;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  long long product = 1;
  int numComponents = 0;
  for (int i = 1; i <= n; i++) {
    long long s = getComponent(i);
    if (s != 0) {
      product *= s;
      product %= k;
      numComponents++;
    }
  }
  if (numComponents == 1) product = 1 % k;
  for (int i = 0; i < numComponents - 2; i++) {
    product *= n;
    product %= k;
  }
  cout << product;
  return 0;
}
