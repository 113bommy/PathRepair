#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int ar[n + 1];
  for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
  int q;
  ar[0] = 0;
  scanf("%d", &q);
  int arr[q];
  for (int i = 0; i < q; i++) scanf("%d", &arr[i]);
  for (int i = 2; i <= n; i++) ar[i] += ar[i - 1];
  int mid, st, fi;
  mid = n / 2;
  st = 1;
  fi = n;
  for (int i = 0; i < q; i++) {
    while (st <= fi) {
      if (ar[mid] >= arr[i] && ar[mid - 1] <= arr[i]) {
        printf("%d\n", mid);
        mid = n / 2;
        st = 1;
        fi = n;
        break;
      } else if (ar[mid] >= arr[i]) {
        fi = mid - 1;
        mid = (st + fi) / 2;
      } else {
        st = mid + 1;
        mid = (st + fi) / 2;
      }
    }
  }
  return 0;
}
