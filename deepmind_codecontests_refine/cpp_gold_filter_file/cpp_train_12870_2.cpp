#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int arr[N], n, x, k, l, r;
long long int ans;
map<pair<int, int>, bool> in;
int main() {
  scanf("%d%d%d", &n, &x, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
  sort(arr, arr + n);
  for (int i = 0; i < n; ++i) {
    int ansl = -1, ansr = -1;
    l = 0;
    r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] / x - (arr[i] - 1) / x == k && arr[i] <= arr[mid])
        l = mid + 1, ansr = mid;
      else {
        if (arr[mid] / x - (arr[i] - 1) / x > k)
          r = mid - 1;
        else
          l = mid + 1;
      }
    }
    l = 0;
    r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] / x - (arr[i] - 1) / x == k && arr[i] <= arr[mid])
        r = mid - 1, ansl = mid;
      else {
        if (arr[mid] / x - (arr[i] - 1) / x > k)
          r = mid - 1;
        else
          l = mid + 1;
      }
    }
    if (ansl != -1 && ansr != -1) ans += ansr - ansl + 1;
  }
  printf("%lld", ans);
  return 0;
}
