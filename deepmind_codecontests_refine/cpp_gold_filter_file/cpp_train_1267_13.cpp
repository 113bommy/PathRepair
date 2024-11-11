#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    int ok = 1;
    for (int j = 1; i + j < n && j <= y; j++) {
      if (A[i + j] < A[i]) ok = 0;
    }
    for (int j = 1; i - j >= 0 && j <= x; j++) {
      if (A[i - j] < A[i]) ok = 0;
    }
    if (ok) {
      ans = i;
      break;
    }
  }
  cout << ans + 1 << '\n';
  return 0;
}
