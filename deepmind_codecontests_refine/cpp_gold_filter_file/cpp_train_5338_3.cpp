#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  ;
  sort(a, a + n, greater<long long>());
  long long k = 0;
  long long b[n];
  for (long long i = 0; i < n; i += 2) b[i] = a[k], k++;
  for (long long i = 1; i < n; i += 2) b[i] = a[k], k++;
  cout << ((n - 1) / 2) << "\n";
  for (long long i = 0; i < n; i++) cout << b[i] << " ";
  cout << "\n";
}
