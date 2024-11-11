#include <bits/stdc++.h>
using namespace std;
bool compare(double a, double b) { return a > b; }
int main() {
  int n;
  scanf("%d", &n);
  vector<double> arr(n);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &arr[i]);
  }
  sort(arr.begin(), arr.end(), compare);
  double max = 0.;
  for (int i = 1; i <= n; i++) {
    double x, sum = 0.;
    for (int j = 0; j < i; j++) {
      x = arr[j];
      for (int k = 0; k < i; k++) {
        if (j != k) x *= 1 - arr[k];
      }
      sum += x;
    }
    if (sum > max) max = sum;
  }
  printf("%.12lf", max);
  return 0;
}
