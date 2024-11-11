#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int M[n][n], a[n];
  memset(a, 0, sizeof a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> M[i][j];
      if (i != j) {
        for (int k = 0; k <= 30; ++k) {
          if (M[i][j] >> k & 1) {
            a[i] |= (1 << k);
            a[j] |= (1 << k);
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
  return 0;
}
