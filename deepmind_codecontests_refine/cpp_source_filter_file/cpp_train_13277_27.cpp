#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  sort(arr, arr + n);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (arr[i] >= ans) {
      ans++;
    }
  }
  printf("%d\n", ans);
}
