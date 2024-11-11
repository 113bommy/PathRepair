#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
int arr[maxn];
int main() {
  int a, b, c, d, e, f, g, h;
  scanf("%d", &a);
  for (d = 0; d < a; d++) scanf("%d", &arr[d]);
  sort(arr, arr + d);
  for (d = g = 1; d < a; d++) {
    if (arr[d] != arr[d - 1] && arr[d] < (arr[d - 1] << 1)) {
      g = 0;
      break;
    }
  }
  printf("%s\n", g ? "YES" : "NO");
  return 0;
}
