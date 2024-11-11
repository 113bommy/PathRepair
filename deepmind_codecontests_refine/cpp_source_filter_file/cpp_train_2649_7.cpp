#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x, a[100005];
  long long sum = 0;
  cin >> n >> x;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    if (x >= 1) {
      sum += a[i] * x;
      x--;
    } else
      sum += a[i];
  }
  cout << sum;
  return 0;
}
