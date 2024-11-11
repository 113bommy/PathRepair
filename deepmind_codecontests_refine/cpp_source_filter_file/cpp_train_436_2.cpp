#include <bits/stdc++.h>
#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
using namespace std;
int q, n;
int main() {
  cin >> q;
  while (q--) {
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    int l = 1e9 + 7, r = -1e9 - 7, Max = 0;
    for (int i = 1; i < n; ++i) {
      if (A[i - 1] == -1 && A[i] != -1) {
        l = min(l, A[i]);
        r = max(r, A[i]);
      } else if (A[i - 1] != -1 && A[i] == -1) {
        l = min(l, A[i - 1]);
        r = max(r, A[i - 1]);
      } else if (A[i - 1] != -1 && A[i] != -1) {
        Max = max(Max, abs(A[i] - A[i - 1]));
      }
    }
    if (l > 1e9) {
      cout << "0 0\n";
    } else if (l == r) {
      cout << "0 " << l << endl;
    } else {
      int k = (l + r) / 2;
      int ans = max(r - k, k - l);
      ans = max(ans, Max);
      cout << ans << ' ' << k << endl;
    }
  }
  return 0;
}
