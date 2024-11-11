#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long n, k;
pair<long long, long long> find_l_r(long long l, long long r) {
  while (r - l > 4 * k + 3) {
    long long m = (l + r) / 2;
    cout << l << ' ' << m << endl;
    string ans;
    cin >> ans;
    if (ans[0] == 'B') {
      exit(0);
    }
    if (ans[0] == 'Y') {
      r = min(n, m + k);
      l = max(1, l - k);
    } else {
      l = max(1, m - k);
      r = min(n, r + k);
    }
  }
  return {l, r};
}
signed solve() {
  srand(time(0));
  long long l = 1, r = n;
  long long f = 1e9;
  while (1) {
    auto kek = find_l_r(l, r);
    l = kek.first;
    r = kek.second;
    long long u = l + rand() % (r - l + 1);
    cout << u << ' ' << u << endl;
    f--;
    if (!f) {
      while (1) {
      }
    }
    string ans;
    cin >> ans;
    if (ans[0] == 'Y') {
      exit(0);
    }
    if (ans[0] == 'B') {
      exit(0);
    }
    l = max(l - k, 1);
    r = min(r + k, n);
  }
}
signed main() {
  cin >> n >> k;
  solve();
}
