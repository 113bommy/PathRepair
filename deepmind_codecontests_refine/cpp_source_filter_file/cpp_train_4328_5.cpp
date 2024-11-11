#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> L(n), R(n);
  int r, l;
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
    r += R[i];
    l += L[i];
  }
  int ans = -1;
  int mx = abs(l - r);
  for (int i = 0; i < n; i++) {
    int ll = l - L[i] + R[i];
    int rr = r - R[i] + L[i];
    if (abs(ll - rr) > mx) {
      mx = abs(ll - rr);
      ans = i;
    }
  }
  cout << ans + 1 << endl;
}
