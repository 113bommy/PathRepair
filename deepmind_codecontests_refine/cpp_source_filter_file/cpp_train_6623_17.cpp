#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  int a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int d = n - x;
  int sum = 0;
  for (long long i = 0; i < d; i++) {
    sum += a[i];
  }
  sum += k * x;
  cout << sum << endl;
  return 0;
}
