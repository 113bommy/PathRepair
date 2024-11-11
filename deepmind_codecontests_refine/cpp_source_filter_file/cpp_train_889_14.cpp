#include <bits/stdc++.h>
using namespace std;
long long n, k, i, a[501], s[501], x, st, d, sc, smax;
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> x;
    s[i] = s[i - 1] + x;
  }
  for (i = 1; i <= k; i++) {
    cin >> st >> d;
    a[i] = s[d] - s[st - 1];
  }
  for (i = 1; i <= k; i++) {
    if (a[i] < 0) sc += a[i];
  }
  cout << sc;
  return 0;
}
