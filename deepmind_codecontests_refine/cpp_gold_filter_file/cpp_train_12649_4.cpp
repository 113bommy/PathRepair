#include <bits/stdc++.h>
using namespace std;
int n;
int* a;
int main() {
  scanf("%d", &n);
  a = new int[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int k = n / 2;
  int res = a[n - 1] - a[0];
  for (int i = 0; i < n - k; i++) {
    res = min(res, a[i + k] - a[i]);
  }
  cout << res;
  return 0;
}
