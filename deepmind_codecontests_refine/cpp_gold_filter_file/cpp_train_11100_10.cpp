#include <bits/stdc++.h>
using namespace std;
const int Max = 505;
int a[Max];
int main() {
  int n, pos;
  long long k;
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == n) {
      pos = i;
    }
  }
  if (pos <= k) {
    printf("%d\n", n);
  } else {
    int cnt = 0, i = 0, j = 1;
    while (cnt < k) {
      if (a[i] > a[j]) {
        j++;
        cnt++;
      } else {
        i = j;
        j += 1;
        cnt = 1;
      }
    }
    printf("%d\n", a[i]);
  }
  return 0;
}
