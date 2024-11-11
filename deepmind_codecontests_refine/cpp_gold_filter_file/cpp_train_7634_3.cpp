#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, t, m;
  cin >> n >> k >> m;
  vector<pair<long long, long long> > a(n - 1);
  for (long long i = 0; i < n - 1; i++) cin >> a[i].first, a[i].second = i + 1;
  cin >> t;
  sort(a.rbegin(), a.rend());
  long long sum = 0;
  for (long long i = 0; i < k; i++) sum += a[i].first;
  long long result = n;
  for (long long i = 0; i < n - 1; i++) {
    long long sp = sum;
    if (i >= k) sp += a[i].first - a[k - 1].first;
    if (m < sp) result = min(result, a[i].second);
  }
  cout << result << endl;
  return 0;
}
