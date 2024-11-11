#include <bits/stdc++.h>
using namespace std;
long long int x, p;
vector<array<long long int, 2>> inclexcl;
long long int query(long long int mid) {
  long long int z = 0;
  for (auto it : inclexcl) {
    long long int cur = mid / it[0];
    z += cur * it[1];
  }
  return mid - z;
}
vector<long long int> v;
void go(long long int pos, long long int sz, long long int prd) {
  if (pos == v.size()) {
    if (sz) {
      if (sz % 2 == 0) {
        inclexcl.push_back({prd, -1});
      } else {
        inclexcl.push_back({prd, 1});
      }
    }
    return;
  }
  go(pos + 1ll, sz, prd);
  go(pos + 1ll, sz + 1ll, prd * v[pos]);
}
long long int prime[1000003];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  for (long long int i = 1; i <= 1e6; i++) {
    prime[i] = i;
  }
  for (long long int i = 2; i <= 1e6; i++) {
    if (prime[i] == i) {
      for (long long int j = 2ll * i; j <= 1e6; j += i) {
        if (prime[j] == j) {
          prime[j] = i;
        }
      }
    }
  }
  long long int t;
  cin >> t;
  while (t--) {
    long long int k;
    cin >> x >> p >> k;
    v.clear();
    inclexcl.clear();
    long long int z = p;
    long long int prev = prime[z];
    while (z != 1) {
      if (prime[z] != prev) {
        v.push_back(prev);
        prev = prime[z];
      }
      z /= prime[z];
    }
    if (prev != 1) {
      v.push_back(prev);
    }
    go(0, 0, 1);
    long long int lo = x + 1ll;
    long long int hi = 3e6;
    long long int sub = query(x);
    long long int ans = x;
    while (lo <= hi) {
      long long int mid = (lo + hi) / 2;
      if (query(mid) - sub < k) {
        lo = mid + 1ll;
      } else {
        ans = mid;
        hi = mid - 1ll;
      }
    }
    cout << ans << "\n";
  }
}
