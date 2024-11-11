#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  while (t--) {
    long long int n, sum = 0, ans = 0, ct = 0, m, l, r, k;
    cin >> n >> r;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) ans++;
    }
    long long int b[n];
    for (long long int i = 0; i < n; i++) {
      long long int g = 0;
      for (long long int j = 0; j < r && (i - j) >= 0; j++) {
        if (a[i - j] == 1) {
          g++;
        }
      }
      for (long long int j = 1; j < r && (i + j) < n; j++) {
        if (a[i + j] == 1) {
          g++;
        }
      }
      b[i] = g;
    }
    for (long long int i = 0; i < n; i++) {
      if (a[i] == 1) {
        long long int mi = INT_MAX;
        for (long long int j = 0; j < r && (i - j) >= 0; j++) {
          mi = min(b[i - j], mi);
        }
        for (long long int j = 1; j < r && (i + j) < n; j++) {
          mi = min(b[i + j], mi);
        }
        if (mi != 1) {
          sum++;
          for (long long int j = 0; j < r && (i - j) >= 0; j++) {
            b[i - j]--;
          }
          for (long long int j = 1; j < r && (i + j) < n; j++) {
            b[i + j]--;
          }
        }
      }
    }
    for (long long int i = 0; i < n; i++) {
      if (b[i] == 0) {
        cout << -1 << '\n';
        return 0;
      }
    }
    cout << ans - sum << '\n';
  }
  return 0;
}
