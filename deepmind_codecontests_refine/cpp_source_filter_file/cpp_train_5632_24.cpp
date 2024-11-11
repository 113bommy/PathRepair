#include <bits/stdc++.h>
using namespace std;
long long int inf = 1e18;
int main() {
  std::cout.precision(0);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  int i, j, k, n, m, t = 1;
  while (t--) {
    cin >> n >> m;
    int a[m];
    map<int, int> M;
    for (i = 0; i < m; i++) {
      cin >> a[i];
      M[a[i]]++;
    }
    int ans = 0;
    for (i = 1; i <= 100; i++) {
      map<int, int> N = M;
      for (j = 0; j < n; j++) {
        map<int, int>::iterator it;
        int f = 0;
        for (it = N.begin(); it != N.end(); it++) {
          if (it->second >= i) {
            it->second -= i;
            f = 1;
            break;
          }
        }
        if (!f) {
          cout << i - 1 << endl;
          return 0;
        }
      }
    }
  }
}
