#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i2 = pair<int, int>;
const int N = 2e5 + 9;
int A[N], B[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    sort(A + 1, A + n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) {
      if (A[i - 1] != A[i]) B[++m] = A[i];
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
      int z = B[i];
      res = max(res, z);
      int j = i;
      while (j >= 1 && z % B[j] == 0) j--;
      if (j != 0) {
        int y = B[j];
        res = max(res, y + z);
        int k = j;
        while (k >= 1 && (y % B[k] == 0 || z % B[k] == 0)) k--;
        if (k != 0) {
          int x = B[k];
          res = max(res, x + y + z);
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}
