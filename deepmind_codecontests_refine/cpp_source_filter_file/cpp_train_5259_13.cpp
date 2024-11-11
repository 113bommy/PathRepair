#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, p, a[100005], max = 0;
  memset(a, 0, sizeof(a));
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> p;
    a[p] = a[p - 1] + 1;
  }
  for (i = 0; i < n; ++i) {
    if (max < a[i]) max = a[i];
  }
  cout << n - max;
  return 0;
}
