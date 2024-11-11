#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[95], i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] > 15) {
    printf("%d", 15);
    return 0;
  } else {
    for (i = 1; i < n; i++) {
      if ((a[i] - a[i - 1]) >= 15) {
        printf("%d", a[i - 1] + 15);
        return 0;
      }
    }
    if ((90 - a[n - 1]) >= 15) {
      printf("%d", a[n - 1] + 15);
      return 0;
    } else {
      printf("90");
      return 0;
    }
  }
}
