#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, max, res = 0;
  cin >> n;
  int* a = new int[n];
  for (int i = 0; i < 2 * n; ++i) {
    cin >> k;
    if (i == 0) {
      a[k - 1] = k;
      max = ++res;
      continue;
    }
    if (a[k - 1] == k) {
      res--;
    } else {
      a[k - 1] = k;
      res++;
    }
    if (res > max) max = res;
  }
  cout << max;
  return 0;
}
