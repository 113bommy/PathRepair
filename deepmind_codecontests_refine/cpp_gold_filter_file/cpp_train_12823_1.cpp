#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1e9 + 7;
long long INF = 1e18;
const int N = 200000;
const int M = 7;
long long a[12][2001];
long long num[M];
long long kk = 0;
long long mx[12];
long long n;
long long dfs(long long sd, long long k) {
  if (k == kk - 1) {
    long long ans__ = 0;
    for (int i = 0; i < n; i++) {
      ans__ += max(mx[(sd + i) % n], a[i][num[k]]);
    }
    return ans__;
  }
  long long mx2[n];
  for (int i = 0; i < n; i++) {
    long long t1 = (sd + i) % n;
    mx2[t1] = mx[t1];
    mx[t1] = max(mx[t1], a[i][num[k]]);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dfs(i, k + 1));
  }
  for (int i = 0; i < n; i++) {
    mx[i] = mx2[i];
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(20);
  long long t;
  cin >> t;
  while (t--) {
    long long m;
    cin >> n >> m;
    vector<pair<long long, long long> > b;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        b.push_back({a[i][j], j});
      }
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    set<long long> mem;
    long long ii = 0;
    while (mem.size() < M && ii < b.size()) {
      mem.insert(b[ii].second);
      ii++;
    }
    kk = 0;
    for (auto i : mem) {
      num[kk] = i;
      kk++;
    }
    cout << dfs(0, 0) << "\n";
  }
}
