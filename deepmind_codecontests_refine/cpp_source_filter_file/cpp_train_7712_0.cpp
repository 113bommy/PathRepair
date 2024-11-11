#include <bits/stdc++.h>
using namespace std;
long long total;
int main() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long sum1 = 0, sum2 = 0;
  long long ans = 0;
  long long res = 0;
  for (int i = 0, j = n - 1; i <= j;) {
    if (sum1 + a[i] < sum2 + a[j] && i <= j) {
      sum1 += a[i];
      i++;
    }
    if (sum2 + a[j] < sum1 + a[i] && i <= j) {
      sum2 += a[j];
      j--;
    }
    if (sum1 + a[i] == sum2 + a[j] && i <= j) {
      sum1 += a[i];
      sum2 += a[j];
      res = sum1;
      ans = max(ans, res);
      i++;
      j--;
    }
  }
  cout << ans << endl;
}
