#include <bits/stdc++.h>
using namespace std;
const double clf = 1e-8;
const int MMAX = 0x7fffffff;
const int INF = 0xfffffff;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int x, y;
    int A = -INF, B = INF, C = INF, D = -INF;
    for (int i = 0; i < n; i++) {
      int t1, t2, t3, t4;
      cin >> x >> y >> t1 >> t2 >> t3 >> t4;
      if (!t1) A = max(A, x);
      if (!t2) B = min(B, y);
      if (!t3) C = min(C, x);
      if (!t4) D = max(D, y);
    }
    if (A <= C && D <= B) {
      cout << "1 " << A << " " << D << " " << endl;
      continue;
    }
    cout << "0" << endl;
  }
  return 0;
}
