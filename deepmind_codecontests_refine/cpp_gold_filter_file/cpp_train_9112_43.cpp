#include <bits/stdc++.h>
using namespace std;
int n;
double k, arr[10000];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  double low = 0, high = 1000, mid;
  for (int i = 0; i < 300; i++) {
    double given = 0, taken = 0;
    mid = (low + high) / 2.0;
    for (int j = 0; j < n; j++) {
      if (arr[j] > mid)
        taken += arr[j] - mid;
      else if (arr[j] < mid)
        given += mid - arr[j];
    }
    taken = taken - (taken * k) / 100.0;
    if (given <= taken) {
      low = mid;
    } else
      high = mid;
  }
  cout << fixed << setprecision(9) << mid << endl;
  return 0;
}
