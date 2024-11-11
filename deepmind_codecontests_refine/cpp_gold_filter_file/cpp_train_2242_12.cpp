#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int arr[100200];
  char str[100200];
  scanf("%d%*c", &n);
  scanf("%s", str);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (str[sum] == '>') {
      sum += arr[sum];
      if (sum >= n) {
        printf("FINITE\n");
        return 0;
      }
    } else if (str[sum] == '<') {
      sum -= arr[sum];
      if (sum < 0) {
        printf("FINITE\n");
        return 0;
      }
    }
  }
  printf("INFINITE\n");
  return 0;
}
