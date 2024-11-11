#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int a[n];
  long long int b[n];
  long long int c[n + 2];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < n; i++) {
    cin >> b[i];
  }
  c[0] = 0;
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    if (b[i] == 0) {
      c[i + 1] = a[i];
    } else {
      c[i + 1] = 0;
      ans += a[i];
    }
  }
  for (long long int i = 2; i <= n; i++) {
    c[i] += c[i - 1];
  }
  long long int maxi = -1;
  for (long long int i = 1; i <= n - k + 1; i++) {
    maxi = max(maxi, c[i + k - 1] - c[i - 1]);
  }
  cout << ans + maxi;
}
