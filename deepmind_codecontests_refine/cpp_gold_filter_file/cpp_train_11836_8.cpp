#include <bits/stdc++.h>
#pragma GCC optimize "O3,no-stack-protector"
using namespace std;
const int MAXN = 1e5 + 7;
vector<int> G[MAXN];
bool blo[MAXN];
short odw[MAXN];
bool tried[MAXN];
int n, m;
bool dfs(int v) {
  if (blo[v] == true) return false;
  odw[v] = 1;
  for (auto w : G[v]) {
    if (odw[w] == 0) {
      if (dfs(w)) return true;
    } else if (odw[w] == 1) {
      for (int i = 1; i <= n; i++) {
        if (odw[i] != 1) tried[i] = true;
      }
      return true;
    }
  }
  odw[v] = 2;
  return false;
}
bool check() {
  for (int i = 1; i <= n; i++) {
    odw[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!odw[i]) {
      if (dfs(i)) return false;
    }
  }
  return true;
}
inline double elapsed() { return clock() / (double)CLOCKS_PER_SEC; }
int main(int argc, char **argv) {
  srand(15061994);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b);
  }
  vector<int> KAN;
  for (int i = 1; i <= n; i++) {
    KAN.push_back(i);
  }
  random_shuffle(KAN.begin(), KAN.end());
  for (int i = 0; elapsed() <= 0.60 and i < int(KAN.size()); i++) {
    blo[KAN[i]] = true;
    if (!tried[KAN[i]] and check()) {
      cout << KAN[i] << "\n";
      exit(0);
    }
    blo[KAN[i]] = false;
  }
  cout << -1 << "\n";
  return 0;
}
