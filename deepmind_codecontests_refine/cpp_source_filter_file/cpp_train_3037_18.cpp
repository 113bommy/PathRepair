#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, t, l, r, s, c;
  cin >> n;
  long long int A[n], Ans[n + 1];
  for (i = 0; i < n; i++) {
    cin >> A[i];
  }
  Ans[0] = 0;
  for (i = 0; i < n; i++) {
    Ans[i + 1] = Ans[i] + A[i];
  }
  cin >> t;
  while (t--) {
    cin >> l >> r;
    c = (Ans[r - 1] - Ans[l - 1]) / 10;
    cout << c << "\n";
  }
  return 0;
}
