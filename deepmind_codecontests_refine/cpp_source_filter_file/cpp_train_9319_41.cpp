#include <bits/stdc++.h>
using namespace std;
int a[1001], b[1001];
int main(void) {
  int n, maxi = 0, sum1 = 0, sum2 = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  int l = 1, r = n;
  for (int i = 1; l <= n / 2; l++) {
    for (int j = l; j <= r; j++) {
      sum1 |= a[j];
      sum2 |= b[j];
    }
    if (sum1 + sum2 > maxi) maxi = sum1 + sum2;
    sum1 = 0;
    sum2 = 0;
    l++;
    r--;
  }
  cout << maxi;
  return 0;
}
