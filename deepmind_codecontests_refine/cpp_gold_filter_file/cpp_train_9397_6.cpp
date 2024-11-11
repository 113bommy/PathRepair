#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long long p = 1;
  while (2 * p <= n) p *= 2;
  vector<pair<long long, long long> > ans;
  function<void(long long, long long)> make = [&](long long a, long long b) {
    if (a == b) return;
    long long mid = (a + b) >> 1;
    make(a, mid);
    make(mid + 1, b);
    long long i = a, j = mid + 1;
    while (i <= mid) {
      ans.push_back(make_pair(i, j));
      ++i;
      ++j;
    }
  };
  make(1, p);
  if (p != n) make(n - p + 1, n);
  cout << (long long)(ans).size() << '\n';
  for (auto i : ans) cout << i.first << " " << i.second << '\n';
}
