#include <bits/stdc++.h>
using namespace std;
long a[100500], b[100500];
long P = 1000;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long n, t, r, last = 0;
  cin >> n >> t >> r;
  for (int i = 0; i < n; i++) {
    long x;
    cin >> x;
    a[P + x] = 1;
    last = max(last, P + x);
  }
  long need = t, ans = 0;
  for (int i = last; i >= 0; i--) {
    if (a[i] == 1) {
      need = r;
      for (int j = i - t + 1; j < i; j++) {
        if (b[j] == 2) {
          need--;
        }
      }
      for (int j = i - t + 1; j < i; j++) {
        if (b[j] != 2 && need > 0) {
          ans++;
          need--;
          b[j] = 2;
        }
      }
    }
  }
  for (int i = last; i >= 300; i--) {
    if (a[i] == 1) {
      long cur = 0;
      for (int j = i - 1; j > i - t; j--) {
        if (b[j] == 2) cur++;
      }
      if (cur < r) {
        cout << "-1";
        return (0);
      }
    }
  }
  cout << ans;
  return 0;
}
