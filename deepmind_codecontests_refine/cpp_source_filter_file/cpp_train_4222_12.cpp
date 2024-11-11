#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005], brr[100005];
int main() {
  int i, a;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    arr[a] = i;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    brr[arr[a]] = i;
  }
  int len = 0;
  for (i = n - 1; i >= 0; i--) {
    int t = upper_bound(arr, arr + len, brr[i]) - arr;
    if (t < len)
      arr[t - 1] = brr[i];
    else
      arr[len++] = brr[i];
  }
  printf("%d\n", len);
  return 0;
}
