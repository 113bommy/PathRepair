#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long a[n];
  long long c[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]] = i + 1;
  }
  long long b[n];
  for (long long i = 0; i < n; i++) cin >> b[i];
  long long tusa = 0;
  for (long long i = 0; i < n; i++) {
    cout << max(0ll, c[b[i]] - tusa) << " ";
    if (tusa < c[b[i]]) tusa += c[b[i]];
  }
  return 0;
}
