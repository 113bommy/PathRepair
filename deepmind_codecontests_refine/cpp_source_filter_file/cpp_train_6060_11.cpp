#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int A[3], B[3], C[8];
    for (int i = (3) - 1; i >= 0; i--) cin >> A[i];
    for (int i = (3) - 1; i >= 0; i--) cin >> B[i];
    for (int i = (8) - 1; i >= 1; i--) cin >> C[i];
    for (int i = 0; i < (3); i++) {
      int space = A[i] + B[i];
      for (int j = 1; j < (8); j++) {
        if (j & (1 << i)) space -= C[j];
      }
      if (space < 0) {
        cout << -1 << nl;
        goto done;
      }
    }
    for (int i = 0; i < (C[7] + 1); i++) {
      for (int j = 0; j < (C[6] + 1); j++) {
        int lof = C[7] + C[6] + C[5] - i - j - B[2];
        int hif = A[2] - i - j;
        hif = min(hif, C[5]);
        lof = max(lof, 0);
        if (hif < lof) continue;
        int hit = A[1] - i - j;
        int lot = C[7] + C[6] + C[3] - i - j - B[1];
        hit = min(hit, C[3]);
        lot = max(hit, 0);
        if (hit < lot) continue;
        int los = C[7] + C[5] + C[3] - i - B[0];
        int his = A[0] - i;
        if (his < lof + lot || los > hit + hif) {
          continue;
        }
        for (int a = lof; a < (hif + 1); a++) {
          for (int b = lot; b < (hit + 1); b++) {
            if (a + b >= los && a + b <= his) {
              int one = min(C[1], A[0] - i - a - b);
              int two = min(C[2], A[1] - i - j - b);
              int four = min(C[4], A[2] - i - j - a);
              cout << i << " " << j << " " << a << " " << four << " " << b
                   << " " << two << " " << one << nl;
              goto done;
            }
          }
        }
      }
    }
    cout << -1 << nl;
  done:;
  }
  return 0;
}
