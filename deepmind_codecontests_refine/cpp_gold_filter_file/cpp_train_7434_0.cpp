#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, m, sum = 0;
  cin >> n >> d;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  cin >> m;
  if (m == n)
    cout << sum << endl;
  else if (m < n) {
    int sum1 = 0;
    sort(arr, arr + n);
    for (int i = 0; i < m; i++) sum1 += arr[i];
    cout << sum1 << endl;
  } else {
    int fine = (m - n) * d;
    cout << sum - fine << endl;
  }
  return 0;
}
