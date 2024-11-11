#include <bits/stdc++.h>
using namespace std;
int heatable(int *a, int l, int r) {
  while (r >= l) {
    if (a[r--]) {
      return r + 1;
    }
  }
  return -1;
}
int main() {
  int n, r, answer = 0;
  cin >> n >> r;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (r > n && a[i]) {
      cout << 1;
      return 0;
    }
  }
  if (r > n) {
    cout << -1;
    return 0;
  }
  for (int i = r - 1, j = 0; j + r - 1 < n;
       j = heatable(a, j, i) + 1, i = min(n - 1, j + 2 * r - 2), answer++) {
    if (heatable(a, j, i) == -1) {
      cout << -1;
      return 0;
    }
  }
  cout << answer;
}
