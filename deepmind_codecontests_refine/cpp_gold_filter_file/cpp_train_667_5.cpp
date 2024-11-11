#include <bits/stdc++.h>
using namespace std;
int n;
double a[30], b[30], V;
bool cancook(double x) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    if (a[i] * x > b[i]) return 0;
    sum = sum + (a[i] * x);
  }
  if (sum > V) return 0;
  return 1;
}
int main() {
  cin >> n >> V;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  double low = 0.0, high = V, mid, c = 0.0;
  while (low <= high) {
    mid = (low + high) / 2;
    if (cancook(mid))
      c = mid, low = mid + (1e-10);
    else
      high = mid - (1e-10);
  }
  double sum = 0.0;
  for (int i = 0; i < n; i++) sum = sum + (a[i] * c);
  printf("%lf", sum);
}
