#include <bits/stdc++.h>
using namespace std;
long long int a[30];
int main() {
  long long int i, n;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long int sum = a[n - 1];
  for (i = n - 2; i >= 0; i--) {
    if (a[i + 1] == 0) continue;
    if (a[i] >= a[i + 1]) {
      a[i] = a[i + 1] - 1;
      sum += a[i];
    } else
      sum += a[i];
  }
  cout << sum << endl;
  return 0;
}
