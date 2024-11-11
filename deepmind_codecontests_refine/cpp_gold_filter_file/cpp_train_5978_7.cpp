#include <bits/stdc++.h>
#pragma optimize("Ofast")
#pragma target("avx,fma")
#pragma optimize("unroll-loops")
using namespace std;
const int N = 1e6 + 1;
long long int n;
vector<long long int> t[2 * N];
void build() {
  for (long long int i = N - 1; i > 0; --i) {
    t[i].resize(t[i << 1].size() + t[i << 1 | 1].size());
    merge(t[i << 1].begin(), t[i << 1].end(), t[i << 1 | 1].begin(),
          t[i << 1 | 1].end(), t[i].begin());
  }
}
long long int query(long long int x, long long int y) {
  long long int l = x, r = y, res = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      res += (lower_bound(t[l].begin(), t[l].end(), y) - t[l].begin());
      ++l;
    }
    if (r & 1) {
      --r;
      res += (lower_bound(t[r].begin(), t[r].end(), y) - t[r].begin());
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int q;
  cin >> n >> q;
  vector<pair<long long int, long long int> > a(n);
  for (long long int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  for (long long int i = 0; i < n; ++i) {
    t[a[i].first + N].push_back(a[i].second);
  }
  build();
  while (q--) {
    long long int x, prev = 0, c, ans = n;
    cin >> c;
    vector<long long int> tmp(c);
    for (long long int i = 0; i < c; ++i) {
      cin >> x;
      ans -= query(prev + 1, x);
      prev = x;
    }
    ans -= query(prev + 1, N);
    cout << ans << '\n';
  }
  return 0;
}
