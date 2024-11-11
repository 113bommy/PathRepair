#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
double arr[N], arr2[N];
long long n, d;
double power(double n, int m) {
  double res = 1;
  while (m > 0) {
    res = res * n;
    m--;
  }
  return res;
}
double bs() {
  double res;
  double low = 0, high = 1e12;
  double mid;
  for (int i = 0; i < 100; i++) {
    mid = (low + high) / 2.00;
    double sum = 0;
    double x = 0, y = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] > mid) {
        x += arr[i] - mid;
      } else
        y += mid - arr[i];
    }
    x -= ((x * d) / 100.00);
    if (x >= y) {
      low = mid + 1;
      res = mid;
    } else
      high = mid - 1;
  }
  return res;
}
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cout << fixed << setprecision(11) << bs();
}
