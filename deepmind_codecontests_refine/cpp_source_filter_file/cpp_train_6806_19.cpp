#include <bits/stdc++.h>
using namespace std;
int a[100100], le[100100], ri[100100];
int n;
int main() {
  scanf("%d", &n);
  for (int i = (1), _b = (n); i <= _b; i++) scanf("%d", &a[i]);
  for (int i = (2), _b = (n); i <= _b; i++) {
    int left = i - 1;
    while ((left > 0) && (a[left] <= a[i])) left = le[left];
    le[i] = left;
  }
  ri[n] = n + 1;
  for (int i = (n - 1), _a = (1); i >= _a; i--) {
    int right = n + 1;
    while ((right < n + 1) && (a[right] <= a[i])) right = ri[right];
    ri[i] = right;
  }
  int res = 0;
  for (int i = (1), _b = (n); i <= _b; i++) {
    if (le[i] != 0) res = max(res, a[i] ^ a[le[i]]);
    if (ri[i] != n + 1) res = max(res, a[i] ^ a[ri[i]]);
  }
  cout << res;
  return 0;
}
