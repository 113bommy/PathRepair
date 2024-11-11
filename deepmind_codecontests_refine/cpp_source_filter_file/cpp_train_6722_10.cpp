#include <bits/stdc++.h>
using namespace std;
const int MAXM = 2e5 + 5;
long long a[MAXM];
int main() {
  int n, i, j, k;
  cin >> n;
  int l, r;
  long long minm = INT_MAX;
  for (i = 1; i < n; i++) {
    int p = n / i;
    if (p * i == n) {
      if (minm > abs(p - i)) {
        minm = abs(p - i);
        l = p;
        r = i;
      }
    }
  }
  cout << min(l, r) << " " << max(l, r);
  return 0;
}
