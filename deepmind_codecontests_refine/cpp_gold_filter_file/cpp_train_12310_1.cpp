#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int n, k, tmp, tmp1, tmp2, tmp3, flag = 0, sum = 0, count = 0;
    cin >> n >> k;
    long long int arr[n];
    long long int brr[n];
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    for (int j = 0; j < n; j++) {
      cin >> brr[j];
    }
    sort(arr, arr + n);
    sort(brr, brr + n);
    tmp = 0;
    tmp2 = 0;
    while (k > 0 && tmp < n) {
      if (arr[tmp] < brr[n - tmp2 - 1]) {
        arr[tmp] = brr[n - tmp2 - 1];
        k = k - 1;
        tmp2 = tmp2 + 1;
      }
      tmp = tmp + 1;
    }
    for (int j = 0; j < n; j++) {
      sum += arr[j];
    }
    cout << sum << "\n";
  }
}
