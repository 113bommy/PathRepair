#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  long int sum = m;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    long int max = arr[i];
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > max) {
        max = arr[j];
      }
    }
    if (max != arr[i]) {
      long int k = m / arr[i];
      k = (m % arr[i]) + (k * max);
      if (sum < k) {
        sum = k;
      }
    } else {
      continue;
    }
  }
  cout << sum;
}
