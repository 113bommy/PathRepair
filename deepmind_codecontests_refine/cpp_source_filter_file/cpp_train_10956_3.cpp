#include <bits/stdc++.h>
using namespace std;
long long get(string& s) {
  long long res = 0;
  for (auto x : s) {
    res <<= 1;
    if (x == '1') res++;
  }
  return res;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  string a[n];
  long long b[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = get(a[i]);
  }
  long long required = ((1 << m) - n - 1) / 2;
  long long l = 0;
  long long r = (1 << m) - 1;
  long long ans = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long ct = 0;
    for (long long i = 0; i < n; i++) {
      if (b[i] < mid) {
        ct++;
      }
    }
    long long index = mid - ct;
    if (index <= required) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  string answer = bitset<61>(ans).to_string();
  for (long long i = 0; i < m; i++) {
    cout << answer[61 - m + i];
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
