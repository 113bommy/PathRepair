#include <bits/stdc++.h>
using namespace std;
int n, x, k, arr[10000000];
bool bener;
int main() {
  scanf("%d", &n);
  bener = true;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &k);
    if (x == arr[k]) {
      arr[k] = x + 1;
    } else if (x < arr[k]) {
      continue;
    } else {
      printf("NO\n");
      bener = false;
      break;
    }
  }
  if (bener) {
    printf("YES\n");
  }
}
