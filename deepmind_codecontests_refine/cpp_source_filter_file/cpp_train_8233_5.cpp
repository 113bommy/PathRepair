#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5;
map<pair<long long, long long>, long long> mp;
long long p[N], sfdss[N];
long long A[N];
long long find(long long first) {
  if (p[first] != first) p[first] = find(p[first]);
  return p[first];
}
signed main() {
  long long n, m;
  cin >> m >> n;
  for (long long i = 1; i <= m; i++) p[i] = i, sfdss[i] = 1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) scanf("%lld", &A[i]);
    for (long long j = 1; j < m; j++) mp[{A[j - 1], A[j]}]++;
  }
  for (auto it : mp) {
    if (it.second == n) {
      long long a = it.first.first, b = it.first.second;
      long long pa = find(a), pb = find(b);
      if (pa != pb) {
        p[pb] = pa;
        sfdss[pa] += sfdss[pb];
      }
    }
  }
  long long res = 0;
  for (long long i = 1; i <= m; i++) {
    if (p[i] == i) {
      long long first = sfdss[i];
      res = res + (first + 1) * first / 2;
    }
  }
  cout << res << endl;
}
