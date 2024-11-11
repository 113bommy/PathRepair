#include <bits/stdc++.h>
using namespace std;
void input() {
  double r;
  long long int n;
  cin >> n >> r;
  double a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  double y[n];
  for (int i = 0; i < n; i++) {
    y[i] = 0;
    if (i == 0) {
      y[i] = r;
    } else {
      for (int j = i - 1; j >= 0; j--) {
        if (abs(a[i] - a[j]) <= (2 * r)) {
          double k = abs(a[i] - a[j]);
          k *= k;
          double k1 = 4 * r * r;
          y[i] = max(y[i], sqrt(k1 - k) + y[j]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(20) << y[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  return 0;
}
