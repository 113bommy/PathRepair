#include <bits/stdc++.h>
using namespace std;
bool binary_search(double &mid, double *E, double &err, int n, int k);
int main() {
  int n, k;
  cin >> n >> k;
  double *E = new double[n];
  for (int i = 0; i < n; i++) {
    cin >> E[i];
  }
  sort(E, E + n);
  double low = E[0], high = E[n - 1], mid = (low + high) / 2, err = 0,
         t_err = 0;
  while (1) {
    bool t = binary_search(mid, E, err, n, k);
    if (err <= 1e-7) {
      printf("%lf", mid);
      break;
    }
    if (t) {
      high = mid;
      mid = (mid + low) / 2;
      binary_search(mid, E, err, n, k);
    } else {
      low = mid;
      mid = (mid + high) / 2;
      binary_search(mid, E, err, n, k);
    }
  }
  return 0;
}
bool binary_search(double &mid, double *E, double &err, int n, int k) {
  double low_sum = 0;
  double high_sum = 0;
  for (int i = 0; i < n; i++) {
    if (E[i] < mid) {
      low_sum += mid - E[i];
    } else {
      high_sum += E[i] - mid;
    }
  }
  if (low_sum == 0 && high_sum == 0) {
    err = 0;
    return 0;
  }
  if (low_sum / high_sum > 1.0 * (100 - k) / 100) {
    err = low_sum / high_sum - 1.0 * (100 - k) / 100;
    return true;
  } else {
    err = 1.0 * (100 - k) / 100 - low_sum / high_sum;
    return false;
  }
}
