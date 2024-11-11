#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, sum = 0;
  scanf("%lld", &n);
  long long int arr[n];
  for (i = 0; i < n; i++) scanf("%lld", &arr[i]);
  sum += arr[n - 1];
  for (i = n - 2; i >= 0; i--) {
    if (arr[i] >= arr[i + 1]) arr[i] = arr[i + 1] - 1;
    sum += arr[i];
    if (arr[i] == 1) break;
  }
  cout << sum;
}
