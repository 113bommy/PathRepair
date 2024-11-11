#include <bits/stdc++.h>
using namespace std;
const long long int modulo = 1e9 + 7;
void anyade(long long int &a, long long int b) { a = (a + b) % modulo; }
const int limite = 200005;
int n;
int ocupado[limite];
vector<int> g[limite], ginv[limite];
int visto[limite];
int loop[limite];
long long int maneras(int u) {
  visto[u] = 1;
  long long int act = 1;
  vector<int> &ar = g[u];
  for (int i = 0; i < int(ar.size()); i++) anyade(act, maneras(ar[i]));
  return act;
}
void visualiza(int u, int &factor) {
  if (visto[u]) return;
  visto[u] = 1;
  if (loop[u]) factor = 1;
  {
    vector<int> &ar = g[u];
    for (int i = 0; i < int(ar.size()); i++) visualiza(ar[i], factor);
  }
  {
    vector<int> &ar = ginv[u];
    for (int i = 0; i < int(ar.size()); i++) visualiza(ar[i], factor);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    ocupado[a] = 1;
    g[b].push_back(a);
    ginv[a].push_back(b);
    if (a == b) loop[a] = 1;
  }
  long long int sol = 1;
  for (int u = 1; u <= 2 * n; u++)
    if (not ocupado[u]) sol = sol * maneras(u);
  for (int u = 1; u <= 2 * n; u++) {
    if (not visto[u]) {
      int factor = 2;
      visualiza(u, factor);
      sol = factor * sol % modulo;
    }
  }
  cout << sol << endl;
}
