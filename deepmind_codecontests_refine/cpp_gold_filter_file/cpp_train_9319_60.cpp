#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 500;
int a[maxn], b[maxn];
int add(int a[], int l, int r) {
  int sum = a[l++];
  while (l <= r) {
    sum |= a[l++];
  }
  return sum;
}
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
    }
    int ans = -1;
    for (int l = 0; l < n; l++) {
      for (int r = l; r < n; r++) {
        int tsum = add(a, l, r) + add(b, l, r);
        ans = max(ans, tsum);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
