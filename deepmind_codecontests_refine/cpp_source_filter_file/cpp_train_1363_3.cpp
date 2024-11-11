#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  double mx = 0.0;
  double arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i <= n - k; i++) {
    int j = i;
    double sum = 0;
    for (; j < i + k; j++) sum += arr[j];
    mx = max(mx, sum / k);
    double d = 0;
    while (j < i) {
      sum += arr[j];
      d++;
      mx = max(mx, sum / (k + d));
      j++;
    }
  }
  cout << fixed << setprecision(10) << mx << endl;
}
