#include <bits/stdc++.h>
using namespace std;
int arr[100000 + 5];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  reverse(arr, arr + n);
  vector<int> a(4, 0);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    vector<int> b(4, 0);
    b[0] = max(arr[i] + a[2], a[0]);
    b[1] = sum - b[0];
    b[3] = max(arr[i] + a[1], a[3]);
    b[2] = sum - b[3];
    a = b;
  }
  printf("%d %d\n", a[2], a[3]);
  return 0;
}
