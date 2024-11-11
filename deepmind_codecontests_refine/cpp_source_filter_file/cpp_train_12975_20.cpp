#include <bits/stdc++.h>
using namespace std;
void init() { return; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init();
  int n, r;
  cin >> n >> r;
  double x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    y[i] = 0;
    if (i == 0) {
      y[i] = r;
    } else {
      for (int j = 0; j < i; j++) {
        double tmp = sqrtl(4 * r * r - pow(abs(x[i] - x[j]), 2)) + y[j];
        if (tmp > y[i]) y[i] = tmp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(8) << y[i] << " ";
  }
  return 0;
}
