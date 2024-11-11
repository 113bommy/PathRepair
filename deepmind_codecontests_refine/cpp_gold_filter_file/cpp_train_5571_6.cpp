#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[n + 1];
  long long diff[n];
  long long max_count = INT_MIN;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  multiset<long long> eles;
  eles.insert(a[1]);
  long long i = 2, j = 1;
  while (i <= n && j <= n) {
    eles.insert(a[i]);
    long long mini = *eles.begin();
    long long maxi = *eles.rbegin();
    while (maxi - mini > 1) {
      eles.erase(eles.find(a[j]));
      j++;
      maxi = *eles.rbegin();
      mini = *eles.begin();
    }
    long long sz = eles.size();
    max_count = max(max_count, sz);
    i++;
  }
  cout << max_count;
  return 0;
}
