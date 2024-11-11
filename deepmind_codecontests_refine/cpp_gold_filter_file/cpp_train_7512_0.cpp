#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    b[i] = a[i] - a[i - 1];
  }
  sort(b + 1, b + n);
  int sum = 0;
  for (int i = 1; i <= n - k; i++) {
    sum += b[i];
  }
  cout << sum;
  return 0;
}
