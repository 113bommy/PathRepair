#include <bits/stdc++.h>
using namespace std;
int a[100009];
int main() {
  int i, j, k, n, m, d, test;
  while (cin >> n) {
    int total_sum = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      total_sum += a[i];
    }
    int mx_consecutive_sum = 0;
    int go = 0;
    for (i = 1; i <= n; i++) {
      go = go + a[i];
      if (go < 0) go = 0;
      mx_consecutive_sum = max(go, mx_consecutive_sum);
    }
    int con = total_sum - mx_consecutive_sum;
    con = con * -1;
    cout << mx_consecutive_sum + con << "\n";
  }
  return 0;
}
