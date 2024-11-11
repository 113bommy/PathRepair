#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  for (long long int k = 1; k <= t; k++) {
    int n, w;
    cin >> n >> w;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long sum = 0;
    for (int i = n - 1; i >= n - w; i--) {
      sum += arr[i - w] / arr[i];
    }
    for (int i = n - 2 * w - 1; i >= 0; i--) sum += arr[i];
    cout << sum << endl;
  }
}
