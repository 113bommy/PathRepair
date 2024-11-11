#include <bits/stdc++.h>
using namespace std;
long long int a[100000];
long long int b[100000];
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
    if (i != 1) a[i - 1] = b[i] - b[i - 1];
  }
  sort(a, a + n);
  long long ans = k;
  for (long long i = 1; i <= n - k; i++) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
