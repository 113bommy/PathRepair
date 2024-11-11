#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long int LINF = 1e18;
int main() {
  long long int n, m, l, r;
  cin >> n;
  long long int a[n];
  long long int k = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    k = k + a[i];
  }
  cin >> m;
  long long int b[100000 + 1] = {0};
  while (m--) {
    cin >> l >> r;
    for (long long int i = l; i <= r; i++) {
      b[i] = 1;
    }
  }
  sort(a, a + n);
  long long int sum = 0;
  long long int f = 0;
  long long int i = 0;
  while (i < n) {
    sum = sum + a[i];
    while (b[sum] == 0 && sum <= r && i < n - 1) {
      i++;
      sum = sum + a[i];
    }
    if (sum > r) {
      f = 1;
      break;
    }
    i++;
  }
  if (f == 0) {
    if (sum < r) {
      if (b[sum] == 0) {
        sum++;
      }
    }
    cout << sum;
  } else {
    cout << -1;
  }
  return 0;
}
