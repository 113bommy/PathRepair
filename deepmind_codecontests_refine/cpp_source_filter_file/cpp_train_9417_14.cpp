#include <bits/stdc++.h>
using namespace std;
int a[200010];
inline int mymax(int a, int b) { return a > b ? a : b; }
inline int bin_search(int l, int r, int val) {
  int mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (a[mid] == val)
      return mid - 1;
    else if (a[mid] > val)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int mmax = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == 0 || a[i] != a[i - 1]) {
        int tmp = a[i] + a[i];
        while (tmp <= a[n - 1]) {
          int pos = bin_search(0, n - 1, tmp);
          mmax = mymax(mmax, a[pos] % a[i]);
          tmp += a[i];
        }
        mmax = mymax(mmax, a[n - 1] % a[i]);
      }
    }
    printf("%d\n", mmax);
  }
  return 0;
}
