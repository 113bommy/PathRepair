#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  char a[123][123];
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      a[i][j] = '*';
    }
  }
  long long mid = (n / 2 + 1);
  for (long long i = 1; i <= n / 2 + 1; i++) {
    for (long long j = mid - (i - 1); j <= mid; j++) {
      a[j][i] = 'D';
    }
    for (long long j = mid; j <= mid + (i - 1); j++) {
      a[j][i] = 'D';
    }
  }
  for (long long i = n; i >= n / 2 + 1; i--) {
    for (long long j = mid - (n - i); j <= mid; j++) {
      a[j][i] = 'D';
    }
    for (long long j = mid; j <= mid + (n - i); j++) {
      a[j][i] = 'D';
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      cout << a[i][j];
    }
    cout << "\n";
  }
  return 0;
}
