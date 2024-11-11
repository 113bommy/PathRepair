#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  scanf("%d", &n);
  int arr[n];
  for (i = 0; i < n; ++i) scanf("%d", &arr[i]);
  vector<int> v(arr, arr + n);
  j = n / 2;
  sort(v.begin(), v.end());
  for (i = 0; i < j; ++i) {
    if (i != (n - 1 - i))
      printf("%d %d ", v[i], v[n - 1 - i]);
    else {
      printf("%d", v[i]);
      break;
    }
  }
  return 0;
}
