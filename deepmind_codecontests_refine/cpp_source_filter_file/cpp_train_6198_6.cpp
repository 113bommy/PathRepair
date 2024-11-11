#include <bits/stdc++.h>
using namespace std;
int n, r[17], m[17];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> m[i];
  for (int i = 0; i < n; ++i) cin >> r[i];
  int cnt = 0;
  for (int i = 1; i <= 10000; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i % m[j] == r[j]) {
        cnt++;
        break;
      }
    }
  }
  cout.precision(6);
  cout << fixed << cnt / 10000.0;
  return 0;
}
