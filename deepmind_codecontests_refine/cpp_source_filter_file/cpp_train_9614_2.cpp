#include <bits/stdc++.h>
using namespace std;
int n, a[1000001], b, c, d, e, g[101], sum, h[101];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= 5; i++) cin >> h[i];
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    for (int j = 5; j >= 1; j--)
      if (h[j] <= sum) {
        b = sum / h[j];
        sum -= b * h[j];
        g[j] += b;
        break;
      }
    for (int j = 5; j >= 1; j--)
      if (h[j] <= sum) {
        b = sum / h[j];
        sum -= b * h[j];
        g[j] += b;
        break;
      }
    for (int j = 5; j >= 1; j--)
      if (h[j] <= sum) {
        b = sum / h[j];
        sum -= b * h[j];
        g[j] += b;
        break;
      }
    for (int j = 5; j >= 1; j--)
      if (h[j] <= sum) {
        b = sum / h[j];
        sum -= b * h[j];
        g[j] += b;
        break;
      }
    for (int j = 5; j >= 1; j--)
      if (h[j] <= sum) {
        b = sum / h[j];
        sum -= b * h[j];
        g[j] += b;
        break;
      }
  }
  for (int i = 1; i <= 5; i++) cout << g[i] << " ";
  cout << endl << sum << endl;
  return 0;
}
