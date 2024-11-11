#include <bits/stdc++.h>
using namespace std;
void debug_arr(vector<long long> &a) {
  long long len = a.size();
  for (long long i = 0; i < len; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
const long long mod = 1e9 + 7;
const long long mod1 = 998244353;
void solve() {
  long long n;
  cin >> n;
  string second;
  cin >> second;
  if (n <= 2) {
    cout << 0 << "\n";
    return;
  }
  long long ans = 0;
  long long seg = 1;
  vector<long long> seglen;
  for (long long i = 1; i < n; ++i) {
    if (second[i] == second[i - 1])
      seg++;
    else {
      seglen.push_back(seg);
      seg = 1;
    }
  }
  if (second[0] == second[n - 1] && seglen.size() > 0)
    seglen[0] += seg;
  else if (second[0] == second[n - 1] && seglen.size() == 0)
    seglen.push_back(seg + 1);
  else
    seglen.push_back(seg);
  for (auto el : seglen) {
    ans += el / 3;
  }
  cout << ans << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
