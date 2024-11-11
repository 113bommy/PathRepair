#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double b, all = 0, a[101], av;
  cin >> n >> b;
  all = b;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all += a[i];
  }
  av = all / n;
  for (int i = 1; i <= n; i++) {
    if (a[i] > b) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%.6lf\n", av - a[i]);
  }
  return 0;
}
