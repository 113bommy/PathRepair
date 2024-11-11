#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long k;
  cin >> n >> k;
  long long arr[n];
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  sort(arr, arr + n);
  int p1 = 0;
  int p2 = n - 1;
  int flag = 0;
  while (arr[p1] != arr[p2]) {
    while (arr[p1 + 1] == arr[p1]) p1++;
    while (arr[p2 - 1] == arr[p2]) p2--;
    if (p1 < n - 1 - p2) {
      if (k - (p1 + 1) * (arr[p1 + 1] - arr[p1]) >= 0) {
        k -= (p1 + 1) * (arr[p1 + 1] - arr[p1]);
        p1++;
      } else {
        flag = 1;
        break;
      }
    } else {
      if (k - (n - 1 - p2 + 1) * (arr[p2] - arr[p2 - 1]) >= 0) {
        k -= (n - 1 - p2 + 1) * (arr[p2] - arr[p2 - 1]);
        p2--;
      } else {
        flag = 2;
        break;
      }
    }
  }
  if (flag == 1) {
    k = k / (p1 + 1);
    cout << arr[p2] - arr[p1] - k;
  } else if (flag == 2) {
    k = k / (n - 1 - p2 + 1);
    cout << arr[p2] - arr[p1] - k;
  } else {
    cout << 0;
  }
  return 0;
}
