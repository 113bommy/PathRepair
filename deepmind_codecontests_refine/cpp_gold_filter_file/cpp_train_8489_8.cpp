#include <bits/stdc++.h>
using namespace std;
int n, k, t;
int main() {
  cin >> n >> k >> t;
  for (int i = 0; i <= n * k; i++) {
    int fst = 100 * i;
    int sec = n * k * t;
    int fst2 = 100 * (i + 1);
    int sec2 = n * k * t;
    if (fst <= sec && fst2 > sec2) {
      int t = i;
      for (int i = 0; i < n; i++) {
        if (t >= k) {
          cout << k << ' ';
          t -= k;
        } else if (t < k) {
          cout << t << ' ';
          t = 0;
        }
      }
      return 0;
    }
  }
}
