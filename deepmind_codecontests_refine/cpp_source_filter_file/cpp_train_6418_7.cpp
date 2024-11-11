#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n], i, sum1 = 0, sum2 = 0;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (sum1 > 0)
      sum1 = sum1 + arr[i];
    else
      sum2 = sum2 + arr[i];
  }
  cout << sum1 - sum2;
  return 0;
}
