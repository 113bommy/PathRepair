#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxn = 3e5 + 7;
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int n, m;
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  ;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  map<vector<int>, int> hash_;
  const int mask = (1 << 17) - 1;
  for (int i = 0; i < (1 << 17); i++) {
    vector<int> t(n);
    for (int j = 0; j < n; j++) {
      t[j] = __builtin_popcount((a[j] & mask) ^ i);
    }
    hash_[t] = i;
  }
  for (int i = 0; i < (1 << 16); i++) {
    vector<int> t(n), p(n);
    int mx = 0;
    for (int j = 0; j < n; j++) {
      t[j] = __builtin_popcount((a[j] >> 16) ^ i);
      mx = max(t[j], mx);
    }
    for (int sum = mx; sum <= 30; sum++) {
      for (int j = 0; j < n; j++) {
        p[j] = sum - t[j];
      }
      if (hash_.count(p)) {
        cout << hash_[p] + (i << 16) << endl;
        return 0;
      }
    }
  }
  cout << "-1" << endl;
  return 0;
}
