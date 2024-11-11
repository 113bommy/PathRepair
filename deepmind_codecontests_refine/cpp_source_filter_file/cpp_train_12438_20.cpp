#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a < b) return b;
  return a;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
bool okay(long long arr[], long long n, double d) {
  if (n <= 3) return true;
  double p = 2.0 * d + arr[0];
  long long i = 0;
  while (i < n && (double)arr[i] <= p) i++;
  if (i == n) return true;
  p = 2.0 * d + arr[i];
  while (i < n && (double)arr[i] <= p) i++;
  if (i == n) return true;
  p = 2.0 * d + arr[i];
  while (i < n && (double)arr[i] <= p) i++;
  return i == n;
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  if (n <= 3) {
    cout << 0 << "\n";
    if (n == 1)
      cout << arr[0] << " " << arr[0] << " " << arr[0] << "\n";
    else if (n == 2)
      cout << arr[0] << " " << arr[1] << " " << arr[1] << "\n";
    else
      cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    return;
  }
  double ans = 1e9;
  double low = 0.0, high = 1000000000.0;
  while (high - low > 1e-7) {
    double mid = low * 1.0 + 0.5 * (high - low);
    if (okay(arr, n, mid)) {
      high = mid;
    } else
      low = mid;
  }
  printf("%0.7f\n", high);
  double d = high;
  float p = 2.0 * d + arr[0];
  long long i = 0;
  printf("%0.7f ", d + arr[min(i, n - 1)]);
  while (i < n && (double)arr[i] <= p) i++;
  p = 2.0 * d + arr[min(i, n - 1)];
  printf("%0.7f ", d + arr[min(i, n - 1)]);
  while (i < n && (double)arr[i] <= p) i++;
  p = 2.0 * d + arr[min(i, n - 1)];
  printf("%0.7f ", d + arr[min(i, n - 1)]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
