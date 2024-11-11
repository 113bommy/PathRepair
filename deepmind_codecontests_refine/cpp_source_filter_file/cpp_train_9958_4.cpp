#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005];
int main() {
  long long n, m, sum1, sum2;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  int ans = 0;
  if (m >= n) {
    sum1 = a[0];
    sum2 = b[0];
    for (int i = 0, j = 0; j < m;) {
      if (sum1 == sum2) {
        ans++;
        i++;
        j++;
        sum1 = a[j];
        sum2 = b[i];
      } else if (sum1 > sum2) {
        j++;
        sum2 += b[j];
      } else if (sum1 < sum2) {
        i++;
        sum1 += a[i];
      }
    }
  } else {
    sum1 = a[0];
    sum2 = b[0];
    for (int i = 0, j = 0; i < n;) {
      if (sum1 == sum2) {
        ans++;
        i++;
        j++;
        sum1 = a[j];
        sum2 = b[i];
      } else if (sum1 > sum2) {
        j++;
        sum2 += b[j];
      } else if (sum1 < sum2) {
        i++;
        sum1 += a[i];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
