#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int arr[n + 69];
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  sort(arr, arr + n);
  long long sum = 0, c = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= sum) c++, sum += arr[i];
  }
  printf("%d\n", c);
  return 0;
}
