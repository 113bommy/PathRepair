#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int nxt() {
  int x;
  cin >> x;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n = nxt();
  vector<int> deg(n);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    int v = nxt(), u = nxt();
    v--, u--;
    deg[v]++, deg[u]++;
  }
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    if (deg[i] == 2) return cout << "NO", 0;
  cout << "YES";
  return 0;
}
