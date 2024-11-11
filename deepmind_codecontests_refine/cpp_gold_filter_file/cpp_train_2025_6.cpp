#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[100001], t = 0, elem = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (i > 0 && arr[i] < arr[i - 1]) {
      t++;
      elem = i;
    }
  }
  if (t == 0) {
    puts("0");
    return 0;
  } else if (t == 1 && arr[n - 1] <= arr[0])
    printf("%d", n - elem);
  else
    puts("-1");
  return 0;
}
