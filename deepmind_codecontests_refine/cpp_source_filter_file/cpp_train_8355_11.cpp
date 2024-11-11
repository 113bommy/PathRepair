#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int64_t dr8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int64_t dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int64_t dr4[] = {1, 0, 0, -1};
int64_t dc4[] = {0, 1, -1, 0};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int64_t i, n, j, m, k, l, t;
  int64_t X;
  cin >> X;
  while (X--) {
    int64_t mini = 1e17, minj = 1e17, minlo = 1e17;
    cin >> n >> t >> l;
    bool a = false, b = false, c = true;
    for (i = 100; i >= 0 and c; i--) {
      for (j = 0; j <= 100 and c; j++) {
        a = false;
        b = false;
        int64_t looper = i;
        for (k = 0; k < n and c; k++) {
          if (looper == t) a = true;
          if (looper == l) b = true;
          looper += j;
        }
        looper -= j;
        if (a && b) {
          if (minlo > looper) {
            mini = i;
            minj = j;
            minlo = looper;
          }
        }
      }
    }
    int64_t looper = mini;
    for (i = 0; i < n; i++) {
      cout << looper << " ";
      looper += minj;
    }
    cout << endl;
  }
}
