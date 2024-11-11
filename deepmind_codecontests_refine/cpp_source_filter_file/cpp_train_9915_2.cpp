#include <bits/stdc++.h>
using namespace std;
int a[200010], b[200010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, sum1 = 0, sum2 = 0;
    int max = 0, flag = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        sum1++;
      }
      b[i] = sum1;
    }
    for (int i = 1; i <= n - k + 1; i++) {
      sum2 = b[i + k - 2] - b[i];
      if (sum2 > max) {
        max = sum2;
        flag = i;
      }
    }
    cout << max + 1 << " " << flag << endl;
  }
  return 0;
}
