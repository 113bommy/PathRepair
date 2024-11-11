#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, greater<int>());
  long long b[n];
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      b[i] = a[i];
    } else {
      b[i] = a[i] + b[i - 1];
    }
    sum += b[i];
    if (i != n - 1) {
      sum += a[i + 1];
    }
  }
  cout << sum;
  return 0;
}
