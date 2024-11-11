#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long a[n], sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == k)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
