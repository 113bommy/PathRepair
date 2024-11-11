#include <bits/stdc++.h>
using namespace std;
int main() {
  int test = 1;
  for (int t1 = 0; t1 < test; t1++) {
    int n;
    cin >> n;
    int a[n];
    int temp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      if (temp == 1) {
        ans++;
        a[i] = -1;
      } else
        a[i] = 1;
    }
    int sum, mx;
    sum = mx = 0;
    for (int i = 0; i < n; i++) {
      if (sum + a[i] > 0)
        sum = sum + a[i];
      else
        sum = 0;
      if (sum > mx) mx = sum;
    }
    if (mx = 0) mx = -1;
    ans = ans + mx;
    cout << ans;
  }
  return 0;
}
