#include <bits/stdc++.h>
using namespace std;
char a[8][10];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", &a[i]);
  }
  int idx[k];
  for (int i = 0; i < k; i++) {
    idx[i] = i;
  }
  int res = 1e9;
  do {
    int mn = 1e9, mx = -1;
    for (int i = 0; i < n; i++) {
      int num = 0;
      for (int j = 0; j < k; j++) {
        num = num * 10 + a[i][idx[j]] - '0';
      }
      mn = min(mn, num);
      mx = max(mx, num);
    }
    res = min(res, mx - mn);
  } while (next_permutation(idx, idx + k));
  printf("%d", res);
  return 0;
}
