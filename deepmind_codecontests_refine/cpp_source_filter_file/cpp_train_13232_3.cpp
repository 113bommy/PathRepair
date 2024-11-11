#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l, A[100000], p, d, t;
  cin.tie(0);
  cin >> n >> m >> l;
  for (int i = 0; i < n; ++i) cin >> A[i];
  int c = 0;
  for (int i = 0; i < n;) {
    if (A[i] > l) {
      c++;
      while (i < n && A[i] > l) ++i;
    } else
      ++i;
  }
  for (int i = 0; i < m; ++i) {
    cin >> t;
    if (t == 0)
      cout << c << '\n';
    else {
      cin >> p >> d;
      p--;
      if (A[p] <= l && A[p] + d > l) {
        if (p > 0 && p < n - 1 && A[p - 1] > l && A[p + 1] > l) c--;
        if ((p == 0 || A[p - 1] <= l) && (p == n - 1 || A[p + 1] <= l)) c++;
      }
      A[p] += d;
    }
  }
}
