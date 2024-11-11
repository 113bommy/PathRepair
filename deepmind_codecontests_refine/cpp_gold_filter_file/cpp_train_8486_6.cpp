#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long n2 = n * n;
  long long a[n + 1][n + 1];
  long long s = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = n; j > k - 1; j--) {
      a[i][j] = n2;
      n2--;
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = k - 1; j >= 1; j--) {
      a[i][j] = n2;
      n2--;
    }
  }
  for (long long i = 1; i <= n; i++) {
    s += a[i][k];
  }
  cout << s << "\n";
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
