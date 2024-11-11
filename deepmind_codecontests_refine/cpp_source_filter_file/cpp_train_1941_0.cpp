#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int arr[n + 1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[i]) {
        ans++;
      }
    }
  }
  int m;
  scanf("%d", &m);
  ans = ans & 1;
  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (((r - l + 1) * (r - l)) & 1) ans = !ans;
    if (ans)
      printf("odd\n");
    else
      printf("even\n");
  }
}
