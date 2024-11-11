#include <bits/stdc++.h>
using namespace std;
int n;
int l, r, mid, dmid, w[100005];
int main() {
  scanf("%d", &n);
  if (n % 4) {
    printf("! -1\n");
    return 0;
  }
  printf("? %d\n", 1);
  fflush(stdout);
  scanf("%d", &w[1]);
  printf("? %d\n", n / 2 + 1);
  fflush(stdout);
  scanf("%d", &w[n / 2 + 1]);
  if (w[1] == w[n / 2 + 1]) {
    printf("! 1\n");
    fflush(stdout);
    return 0;
  } else if (w[1] < w[n / 2 + 1]) {
    l = 2;
    r = n / 2;
  } else {
    l = n / 2 + 2;
    r = n;
  }
  while (l < r) {
    mid = (l + r) / 2;
    dmid = (mid + n / 2);
    if (dmid > n) dmid -= n;
    printf("? %d\n", mid);
    fflush(stdout);
    scanf("%d", &w[mid]);
    printf("? %d\n", dmid);
    fflush(stdout);
    scanf("%d", &w[dmid]);
    if (w[mid] == w[dmid]) {
      printf("! %d\n", min(mid, dmid));
      fflush(stdout);
      return 0;
    } else if (w[mid] < w[dmid]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  printf("! -1\n");
  fflush(stdout);
  return 0;
}
