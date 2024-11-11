#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if ((n / 2) % 2) {
    printf("! -1\n");
    fflush(stdout);
  } else {
    int v1, vn;
    printf("? 1\n");
    fflush(stdout);
    scanf("%d", &v1);
    printf("? %d\n", 1 + n / 2);
    fflush(stdout);
    scanf("%d", &vn);
    if (v1 == vn) {
      printf("! 1\n");
      fflush(stdout);
    } else {
      int l = 2, r = n / 2, ok = 0;
      for (; l < r;) {
        int mid = (l + r) >> 1;
        int vm, vmm;
        printf("? %d\n", mid);
        fflush(stdout);
        scanf("%d", &vm);
        printf("? %d\n", mid + n / 2);
        fflush(stdout);
        scanf("%d", &vmm);
        if (vm == vmm) {
          printf("! %d\n", mid);
          fflush(stdout);
          ok = 1;
          break;
        } else {
          if (1ll * (v1 - vn) * (vm - vmm))
            l = mid + 1;
          else
            r = mid;
        }
      }
      if (!ok) {
        printf("! %d\n", l);
        fflush(stdout);
      }
    }
  }
}
