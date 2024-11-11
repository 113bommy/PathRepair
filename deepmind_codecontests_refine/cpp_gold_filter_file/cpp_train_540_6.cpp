#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long hell = LLONG_MAX;
long long find_min(vector<long long>& a, long long num, long long st,
                   long long n) {
  long long mn = max(a[st], a[n - 1 - num]);
  for (long long i = 0; i <= num; i++) {
    long long num1 = num - i;
    long long s = a[st + i];
    long long e = a[n - 1 - num1];
    mn = min(mn, max(s, e));
  }
  return mn;
}
signed solve() {
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  long long k;
  cin >> k;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  k = min(k, m - 1);
  long long mx = 0;
  for (long long i = 0; i <= k; i++) {
    long long j = k - i;
    mx = max(mx, find_min(a, m - k - 1, i, n - j));
  }
  cout << mx << endl;
  return 0;
}
signed main() {
  long long t = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
