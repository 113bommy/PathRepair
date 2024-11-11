#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, a[100];
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int f = 10000000;
  for (int i = 0; i < n; i++) {
    if ((a[i] < k) && (a[i] > 0)) {
      if ((abs(i + 1 - m)) < f) {
        f = abs(i + 1 - m);
      }
    }
  }
  cout << f * 10;
  return 0;
}
