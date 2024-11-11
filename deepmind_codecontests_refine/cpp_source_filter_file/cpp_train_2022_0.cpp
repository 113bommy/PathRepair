#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper")
using namespace std;
const long long mod = (long long)(1e9 + 7);
const long double eps = (1e-9);
const long long oo = (long long)(1e18);
int a[(long long)(1 << 24)];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string second;
    cin >> second;
    vector<bool> mk(26);
    for (auto y : second) mk[y - 'a'] = 1;
    vector<int> kk;
    for (int i = 0; i < 26; i++)
      if (mk[i]) kk.push_back(i);
    for (int j = 0; j < (1 << kk.size()); j++) {
      int b = __builtin_popcount(j);
      int mask = 0;
      for (int k = 0; k < kk.size(); k++)
        if (j & (1 << k)) mask |= (1 << kk[k]);
      if (b & 1)
        a[mask]++;
      else
        a[mask]--;
    }
  }
  for (int i = 0; i < 24; i++)
    for (int j = 0; j < (1 << 24); j++)
      if (j & (1 << i)) a[j] += a[j ^ (1 << i)];
  long long res = 0;
  for (int i = 0; i < (1 << 24); i++)
    res ^= ((long long)a[i] * (long long)a[i]);
  cout << (res) << '\n';
  return 0;
}
