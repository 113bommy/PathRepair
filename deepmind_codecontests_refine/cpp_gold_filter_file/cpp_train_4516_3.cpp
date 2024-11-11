#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
  int n, m, mx = 1000000;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    mx = min(mx, x);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  long long ans = 0;
  int i = n - 1;
  while (i >= 0) {
    int tmp = mx;
    while (tmp-- and i >= 0) {
      ans += arr[i];
      i--;
    }
    tmp = 2;
    while (tmp-- and i >= 0) {
      i--;
    }
  }
  cout << ans;
  return 0;
}
