#include <bits/stdc++.h>
using namespace std;
int mass[179179];
int main() {
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    int t, k, d;
    cin >> t >> k >> d;
    int num = 0;
    for (int j = 0; j < n; j++)
      if (mass[j] <= t) num++;
    if (num < k)
      cout << -1 << endl;
    else {
      int sum = 0;
      for (int j = 0; k > 0; j++) {
        if (mass[j] <= t) {
          sum += j + 1;
          mass[j] = t + d;
          k--;
        }
      }
      cout << sum << endl;
    }
  }
}
