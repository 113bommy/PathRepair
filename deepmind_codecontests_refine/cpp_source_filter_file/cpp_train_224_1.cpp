#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000;
int l[maxN];
int r[maxN];
int t;
int n;
int main() {
  scanf("%d", &t);
  for (t; t > 0; t--) {
    scanf("%d", &n);
    int L = -1e9, R = 1e9;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &l[i], &r[i]);
      if (r[i] < R) R = r[i];
      if (l[i] > L) L = l[i];
    }
    if (L > R)
      printf("0\n");
    else
      printf("%d\n", R - L);
  }
  return 0;
}
