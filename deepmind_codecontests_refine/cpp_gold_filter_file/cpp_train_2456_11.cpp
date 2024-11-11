#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, sum = 0, mins = 1000000001, sumo = 0, sumo1 = 0, k1 = 0;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum = sum + a[i];
    if (a[i] < mins) {
      mins = a[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    sumo = sumo + a[i] - mins;
    if (((a[i] - mins) % k != 0) && (a[i] != mins)) {
      k1 = 1;
      cout << -1;
      break;
    }
  }
  if (k1 != 1) {
    cout << sumo / k;
  }
  return 0;
}
