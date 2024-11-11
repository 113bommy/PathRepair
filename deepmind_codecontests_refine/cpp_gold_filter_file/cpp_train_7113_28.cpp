#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> vis;
vector<long long int> adj[200001];
vector<pair<long long int, long long int>> v;
long long int n, k;
long long int calc(long long int v) {
  long long int res = 0;
  long long int ck = 1;
  while (v / ck > 0) {
    res += v / ck;
    ck = ck * k;
  }
  return res;
}
signed main() {
  cin >> n >> k;
  long long int l = 1, r = n;
  long long int ans = n;
  while (l <= r) {
    long long int mid = (l + r) / 2;
    if (calc(mid) >= n) {
      r = mid - 1;
      ans = min(ans, mid);
    } else {
      l = mid + 1;
    }
  }
  cout << ans;
}
