#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  cin >> n >> q;
  int L[n + 5], R[n + 5];
  int ara[n + 5];
  for (int i = 1; i <= n; i++) {
    cin >> ara[i];
  }
  R[n] = n;
  for (int i = n - 1; i >= 1; i--) {
    if (ara[i] <= ara[i + 1])
      R[i] = R[i + 1];
    else
      R[i] = i;
  }
  L[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (ara[i - 1] >= ara[i]) {
      L[i] = L[i - 1];
    } else {
      L[i] = i;
    }
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (L[r] <= R[l]) {
      cout << "Yes" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
