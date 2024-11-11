#include <bits/stdc++.h>
using namespace std;
int Q, A[255];
int mxtyp;
double mx;
double lgf[1005 * 2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i <= 2000; i++) {
    lgf[i] = lgf[i - 1] + log((double)i);
  }
  cin >> Q;
  while (Q--) {
    int mxa = 0;
    for (int i = 1; i <= 250; i++) {
      cin >> A[i];
      mxa = max(mxa, A[i]);
    }
    int mnp = (mxa & 1) ? mxa / 2 + 1 : mxa / 2;
    mx = -250 * log((double)(2 * mnp + 1));
    mxtyp = 0;
    for (int p = mnp; p <= 1000; p++) {
      double sm = 0;
      double Pi;
      for (int i = 1; i <= 250; i++) {
        Pi = A[i] * log((double)p) - p - lgf[A[i]];
        sm += Pi;
      }
      if (sm > mx) {
        mx = sm;
        mxtyp = 1;
      }
    }
    cout << ((mxtyp) ? "poisson" : "uniform") << '\n';
  }
  return 0;
}
