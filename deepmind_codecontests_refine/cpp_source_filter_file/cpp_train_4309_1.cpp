#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long int n, i;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  if (n == 2 || n == 3) {
    cout << -1;
    return 0;
  }
  long long int a[n];
  if (n % 2 == 0) {
    for (i = 1; i <= n / 2; i += 2) {
      a[i - 1] = i + 1;
    }
    for (i = 2; i <= n / 2; i += 2) {
      a[i - 1] = n - i + 2;
    }
    for (i = n; i > n / 2; i -= 2) {
      a[i - 1] = i - 1;
    }
    for (i = n - 1; i > n / 2; i -= 2) {
      a[i - 1] = n - i;
    }
  } else {
    for (i = 1; i <= n / 2; i += 2) {
      a[i - 1] = i + 1;
    }
    for (i = 2; i <= n / 2 + 1; i += 2) {
      a[i - 1] = n - i + 2;
    }
    for (i = n; i > n / 2 + 1; i -= 2) {
      a[i - 1] = i - 1;
    }
    for (i = n - 1; i > n / 2 + 1; i -= 2) {
      a[i - 1] = n - i;
    }
    a[(n - 1) / 2] = n / 2 + 1;
  }
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
