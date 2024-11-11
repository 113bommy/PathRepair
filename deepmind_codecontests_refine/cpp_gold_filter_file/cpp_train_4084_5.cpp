#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
using namespace std;
const long long mo = 1e9 + 7, sz1 = 2e5 + 5, sz2 = 1e3 + 1;
long long nxt() {
  long long x;
  cin >> x;
  return x;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n = nxt();
  long long arr[n];
  generate(arr, arr + n, nxt);
  long long idx = -1, mx = -1;
  map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 30; j++) {
      if (arr[i] & (1 << j)) mp[j]++;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 30; j++) {
      if (mp[j] != 1) continue;
      if (arr[i] & (1 << j)) {
        if (j > mx) mx = j, idx = i;
      }
    }
  }
  if (idx != -1) swap(arr[0], arr[idx]);
  for (long long i = 0; i < n; i++) cout << arr[i] << ' ';
  return 0;
}
