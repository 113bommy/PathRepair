#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100004];
  int i, b;
  cin >> n;
  long long sum = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (i = 1; i <= n; i++) {
    if (a[i] % 2 == 0)
      sum += a[i];
    else {
      b = a[i];
      sum += a[i];
    }
  }
  if (sum % 2 == 1) sum -= b;
  cout << sum << endl;
}
