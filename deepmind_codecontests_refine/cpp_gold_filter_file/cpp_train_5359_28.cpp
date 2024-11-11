#include <bits/stdc++.h>
using namespace std;
int b, d, g, m, n, B[100], G[100], V[100][100];
int main() {
  memset(B, 0, sizeof B);
  memset(G, 0, sizeof G);
  memset(V, 0, sizeof V);
  cin >> n >> m >> b;
  for (int i = 0, j; i < b; ++i) {
    cin >> j;
    B[j] = 1;
  }
  cin >> g;
  for (int i = 0, j; i < g; ++i) {
    cin >> j;
    G[j] = 1;
  }
  for (b = 0, g = 0; V[b][g] < 2;) {
    B[b] = G[g] = B[b] || G[g];
    ++V[b][g];
    if (++b >= n) b = 0;
    if (++g >= m) g = 0;
  }
  for (int i = 0; i < n; ++i) {
    if (!B[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (!G[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
