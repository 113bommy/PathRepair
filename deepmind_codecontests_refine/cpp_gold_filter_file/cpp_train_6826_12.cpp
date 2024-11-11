#include <bits/stdc++.h>
using namespace std;
int sum[100] = {0};
int main() {
  int n;
  string a[50];
  int a1, b, c, d, e;
  int pl, mi;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> pl >> mi;
    sum[i] += ((100 * pl) - 50 * mi);
    cin >> a1 >> b >> c >> d >> e;
    sum[i] += (a1 + b + c + d + e);
  }
  int max1 = sum[0];
  string ans = a[0];
  for (int i = 0; i < n; i++) {
    if (sum[i] > max1) {
      ans = a[i];
      max1 = sum[i];
    }
  }
  cout << ans << "\n";
  return 0;
}
