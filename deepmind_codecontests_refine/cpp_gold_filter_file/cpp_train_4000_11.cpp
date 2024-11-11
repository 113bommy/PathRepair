#include <bits/stdc++.h>
using namespace std;
int w[111111], p[222222];
int main() {
  int n, m, q;
  long long r = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> q >> w[i];
  sort(w, w + m, greater<int>());
  int k;
  for (k = 1;; k++) {
    p[k] = k * (k - 1) / 2 + 1;
    if (!(k % 2)) p[k] += max((k - 2) / 2, 0);
    if (p[k] > n) break;
  }
  for (int i = 0; i < min((k - 1), m); i++) r += w[i];
  cout << r << endl;
  return 0;
}
