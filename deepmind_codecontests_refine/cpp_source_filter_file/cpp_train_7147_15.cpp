#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long ar[n];
  for (long long i = 0; i < n; i++) cin >> ar[i];
  long long t[n];
  for (long long i = 0; i < n; i++) cin >> t[i];
  long long sum = 0;
  long long pr[n];
  memset(pr, 0, sizeof(pr));
  for (long long i = 0; i < n; i++) {
    if (i) pr[i] += pr[i - 1];
    if (t[i])
      sum += ar[i];
    else
      pr[i] += ar[i];
  }
  long long mx = 0;
  for (long long i = k - 1; i < n; i++) {
    mx = max(mx, (i >= k) ? pr[i] - pr[i - k] : 0);
  }
  cout << sum + mx;
  return 0;
}
