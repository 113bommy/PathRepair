#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, s;
  scanf("%d %d %d", &n, &a, &b);
  int arr[n + 1];
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < a; i++) {
    scanf("%d", &s);
    arr[s - 1] = 1;
  }
  for (int i = 0; i < b; i++) {
    scanf("%d", &s);
    if (!arr[s - 1]) {
      arr[s - 1] = 2;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
  }
  return 0;
}
