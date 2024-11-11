#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, m, i, j, flag;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    flag = 0;
    vector<long long int> N(n), M(m);
    for (i = 0; i < n; i++) cin >> N[i];
    for (i = 0; i < m; i++) cin >> M[i];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (N[i] == M[i]) {
          flag = 1;
          break;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 1) {
      cout << "YES\n";
      cout << 1 << " " << N[i] << "\n";
    } else
      cout << "NO\n";
  }
}
