#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, pdt = 1, modulus = 998244353, mini = 10000000009;
  cin >> n >> m;
  long long a[n], b[m];
  map<long long, long long> mp;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = n - 1; i >= 0; i--) mini = min(mini, a[i]), mp[mini]++;
  if (mini < b[0]) {
    cout << 0;
    return 0;
  }
  for (long long i = 1; i < m; i++) pdt = (pdt * mp[b[i]]) % modulus;
  cout << pdt;
}
