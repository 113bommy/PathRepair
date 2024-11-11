#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t = 0, ctr = 0, stack = 0;
  cin >> n;
  int a[n];
  while (t < n) {
    cin >> a[t];
    t++;
  }
  ctr += a[0];
  for (int i = 1; i < n - 1; i++) {
    int diff = (a[i] - a[i + 1]);
    if (diff < 0) {
      if ((stack + diff) >= 0) {
        stack += diff;
      } else {
        ctr -= (stack + diff);
        stack = 0;
      }
    } else
      stack += diff;
  }
  cout << ctr;
  return 0;
}
