#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[n], ans[n];
  for (long long i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  long long j = 1;
  for (long long i = 0; i < n / 2; ++i) {
    ans[j] = a[i];
    j += 2;
  }
  j = 0;
  for (long long i = n / 2; i < n; ++i) {
    ans[j] = a[i];
    j += 2;
  }
  cout << n / 2 << "\n";
  for (long long i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
