#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, sum, sum1, count = 1;
  cin >> n;
  int arr[4 * n + 1];
  arr[0] = 0;
  for (i = 1; i <= 4 * n - 3; i = i + 4) {
    cin >> arr[i] >> arr[i + 1] >> arr[i + 2] >> arr[i + 3];
    if (i == 1)
      sum = arr[1] + arr[2] + arr[3] + arr[4];
    else {
      sum1 = arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3];
      if (sum1 > sum) count++;
    }
  }
  cout << count;
}
