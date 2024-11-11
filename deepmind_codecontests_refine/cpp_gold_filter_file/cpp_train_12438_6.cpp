#include <bits/stdc++.h>
using namespace std;
int n, arr[(int)2e5 + 5];
double l = 0, h = 10000000000, mid, ans;
bool GO(double m, int *arr, int no) {
  int x = arr[0];
  auto it = upper_bound(arr, arr + no, m * 2 + x);
  for (int i = 0; i < 2; ++i) {
    it = upper_bound(arr, arr + no, m * 2 + x);
    x = *it;
  }
  auto it1 = upper_bound(arr, arr + no, m * 2 + x);
  if (it < arr + no && ((m * 2) + *it) < arr[no - 1])
    return 0;
  else
    return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", arr + i);
  if (n == 3) {
    printf("%f\n", 0.0);
    printf("%.6f %.6f %.6f\n", (double)arr[0], (double)arr[1], (double)arr[2]);
    return 0;
  }
  sort(arr, arr + n);
  for (int i = 0; i < 1000; ++i) {
    mid = (l + h) / 2;
    if (GO(mid, arr, n)) {
      ans = mid;
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%.6f\n", ans);
  auto it = upper_bound(arr, arr + n, arr[0] + ans * 2);
  auto it1 = upper_bound(arr, arr + n, *it + ans * 2);
  printf("%.6f %.6f %.6f\n", arr[0] + ans, *it + ans, *it1 + ans);
}
