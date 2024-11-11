#include <bits/stdc++.h>
using namespace std;
int t, n, aux;
vector<int> ocurrencia;
void solve() {
  cin >> n;
  ocurrencia = vector<int>(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> aux;
    ++ocurrencia[aux];
  }
  int k_total = 0;
  for (int s = 2; s <= 2 * n; s++) {
    int k_local = 0;
    for (int i = 1; i < (s + 1) / 2; i++) {
      if (s - i > n) continue;
      k_local += min(ocurrencia[i], ocurrencia[s - i]);
    }
    if (s % 2 == 0) k_local += ocurrencia[s / 2] / 2;
    k_total = max(k_total, k_local);
  }
  cout << k_total << "\n";
  ;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
