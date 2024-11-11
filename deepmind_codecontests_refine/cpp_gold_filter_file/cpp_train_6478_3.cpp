#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr1[1000], arr2[1000], sum1 = 0, sum2 = 0, k, count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
    sum1 += arr1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
    sum2 += arr2[i];
  }
  k = sum2 - sum1;
  for (int i = 0; i < n; i++) {
    if (arr1[i] == 1 && arr2[i] == 0) count++;
  }
  if (count == 0)
    cout << -1;
  else if (k < 0)
    cout << 1;
  else if (k % count == 0)
    cout << k / count + 2;
  else
    cout << k / count + 2;
}
