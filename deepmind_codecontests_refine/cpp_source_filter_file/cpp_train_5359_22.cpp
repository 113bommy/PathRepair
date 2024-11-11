#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int lucky_b, lucky_g;
  bool B[100] = {0};
  bool G[100] = {0};
  cin >> lucky_b;
  int k = 0;
  for (int i = 0; i < lucky_b; i++) {
    cin >> k;
    B[k] = 1;
  }
  k = 0;
  cin >> lucky_g;
  for (int i = 0; i < lucky_g; ++i) {
    cin >> k;
    G[k] = 1;
  }
  int N = n * m;
  for (int i = 0; i < N; i++) {
    if (B[i % n] || G[i % m]) {
      B[i % n] = 1;
      G[i % m] = 1;
    } else
      continue;
  }
  bool res = true;
  for (int i = 0; i < n; i++) {
    if (B[i] == true)
      continue;
    else
      res = false;
  }
  for (int i = 0; i < m; i++) {
    if (G[i] == true)
      continue;
    else
      res = false;
  }
  if (res)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
