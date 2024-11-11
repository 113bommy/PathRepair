#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int arr[maxn], arr2[maxn];
int main() {
  int n, m, r;
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  for (int i = 0; i < m; i++) {
    scanf("%d", &arr2[i]);
  }
  sort(arr2, arr2 + m);
  if (arr[0] >= arr2[m - 1]) {
    printf("%d\n", r);
  } else {
    long long ans = 0;
    while (r > arr[0]) {
      ans += arr2[m - 1];
      r -= arr[0];
    }
    ans += r;
    cout << ans << endl;
  }
  return 0;
}
