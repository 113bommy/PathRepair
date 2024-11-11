#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, f, s, sum = 0;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  long long int x = v.back();
  v.pop_back();
  v.insert(v.begin(), x);
  cin >> s >> f;
  long long int ans = sum, time;
  for (long long int i = 1; i < n; i++) {
    long long int l = (s - i + n) % n;
    long long int r = (f - i + n) % n;
    sum += (v[l] - v[r]);
    if (sum > ans) ans = sum, time = i;
  }
  cout << time + 1;
}
