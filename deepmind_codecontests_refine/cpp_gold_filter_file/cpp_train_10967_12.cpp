#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, r[202];
  cin >> n >> k;
  for (int i = 0; i < 2 * n + 1; ++i) cin >> r[i];
  cout << r[0] << ' ';
  for (int i = 1; i < 2 * n; ++i) {
    if (k && (i + 1) % 2 == 0 && r[i - 1] < r[i] - 1 && r[i] - 1 > r[i + 1]) {
      --r[i];
      --k;
    }
    cout << r[i] << ' ';
  }
  cout << r[2 * n] << ' ';
  return 0;
}
