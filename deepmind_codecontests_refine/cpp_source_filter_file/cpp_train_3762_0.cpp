#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i;
  cin >> n;
  long int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long int sum = 0, j = 0;
  for (i = 0, j = n - 1; i < j; i++, j--) {
    sum = sum + ((a[i] + a[j]) * (a[i] + a[j]));
  }
  cout << sum;
  return 0;
}
